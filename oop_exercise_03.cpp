// Written by VSNelyubin, m80-206b-19, Original Code, do not steal!

#include <iostream>

#include <cmath>

#include <iomanip>

#include <stdio.h>

#include <stdlib.h>

#include <vector>

double dabs(double inp){
	if(inp<0){return -inp;}
	return inp;
}

class Vertex{
	public:
	double X,Y;
	Vertex operator + (Vertex const &obj) {
	        Vertex res;
	        res.X = X + obj.X;
	        res.Y = Y + obj.Y;
        	return res;
	}
	Vertex operator * (double const &k) {
                Vertex res;
                res.X = X*k;
                res.Y = Y*k;
                return res;
        }
	Vertex operator - (Vertex const &obj) {
                Vertex res;
                res.X = X - obj.X;
                res.Y = Y - obj.Y;
                return res;
        }
        Vertex operator / (double const &k) {
                Vertex res;
                res.X = X/k;
                res.Y = Y/k;
                return res;
        }
	void Vs(double Xx, double Yy){
		X=Xx;
		Y=Yy;
	}

/*	std::ostream& operator << (std::ostream & out) {
        	out << X <<" "<<Y;
	        return out;
	}

	std::istream& operator >> (std::istream & out) {
	        out >> X >> Y;
	        return out;
	}
*/
};

std::ostream& operator << (std::ostream & out, Vertex c) {
        out << c.X <<" "<<c.Y;
        return out;
}

std::istream& operator >> (std::istream & out, Vertex & c) {
	double a,b;
        out >> a >> b;
	c.Vs(a,b);
        return out;
}

/*std::ostream& operator << (std::ostream & out, Vertex c) {
        out << c.X <<" "<<c.Y;
        return out;
}

std::istream& operator >> (std::istream & out, Vertex c) {
        double a,b;
        out >> a >> b;
        c.Vs(a,b);
        return out;
}*/


/*std::ostream& operator << (std::ostream & out, const Vertex & c) {
	out << c.X <<" "<<c.Y;
	return out;
}

std::istream& operator >> (std::istream & out, const Vertex & c) {
	double a,b;
        out >> a >> b;
        c.Vs(a,b);
	return out;
}*/


class Figure{
	public:
	Vertex* cord;
	int verNum;
	Figure(int vern){
		verNum=vern;
		cord=new Vertex[4];
	}
	~Figure(){
		delete[] cord;
	}
	double figArea(){
		if(verNum<3){return 0;}
		double rez=0;
		for(int arei=2;arei<verNum;arei++){
			rez+=dabs((cord[0].X*(cord[arei-1].Y-cord[arei].Y)+cord[arei-1].X*(cord[arei].Y-cord[0].Y)+cord[arei].X*(cord[0].Y-cord[arei-1].Y))/2);
		}
		return rez;
	}
	Vertex finCenter(){
//printf("looking for center\n");
		Vertex rez;
		rez.X=0;rez.Y=0;
		for(int arei=0;arei<verNum;arei++){
			rez=rez+cord[arei];
//std::cout<<rez<<"\n";
		}
		rez=rez/(double)verNum;
//std::cout<<rez<<"\n";

//printf("exiting\n");
		return rez;
	}
	/*void print2std(int pres){
		cout.precision(pres);
		for(int arei=0;arei<verNum;arei++){
			cout<<cord[arei]<<"\n";
		}
	}*/
	/*std::ostream& operator << (std::ostream & out) {
	        for(int arei=0;arei<verNum;arei++){
	                out<<cord[arei]<<"\n";
	        }
	        return out;
	}*/

};

double dist(Vertex a, Vertex b){
	double dx=a.X-b.X;
	dx=dx*dx;
	double dy=a.Y-b.Y;
	dy=dy*dy;
	return sqrt(dx+dy);
}

bool isParallel(Vertex l1b,Vertex l1e,Vertex l2b,Vertex l2e){
	double dx=l1b.X-l1e.X;
	double dy=l1b.Y-l1e.Y;
	double d1=dabs(dx/dy);
//	std::cout<<dx<<" "<<dy<<" "<<d1<<"\n";
	dx=l2b.X-l2e.X;
	dy=l2b.Y-l2e.Y;
	double d2=dabs(dx/dy);
//	std::cout<<dx<<" "<<dy<<" "<<d2<<"\n";
	return d1==d2;
}

class trap : public Figure { //XD public figure
        public:
        trap():Figure(4){
        }
};
        std::istream & operator >> (std::istream & out, trap &c) {
                for(int ani=0;ani<c.verNum;ani++){
                        out >>c.cord[ani];
                }
                if(!(isParallel(c.cord[0],c.cord[1],c.cord[2],c.cord[3])||isParallel(c.cord[1],c.cord[2],c.cord[3],c.cord[0]))){
                        std::cout<<"the figure is not a trapezoid\n";
                }
                return out;
        }

class rectangle : public Figure { //XD public figure
	public:
	rectangle():Figure(4){
	}
};
	std::istream & operator >> (std::istream & out, rectangle &c) {
		for(int ani=0;ani<c.verNum;ani++){
                	out >>c.cord[ani];
		}
		if(!(isParallel(c.cord[0],c.cord[1],c.cord[2],c.cord[3])&&isParallel(c.cord[1],c.cord[2],c.cord[3],c.cord[0]))){
			std::cout<<"the figure is not a parallelogram\n";
		}
		if(dist(c.cord[0],c.cord[2])!=dist(c.cord[1],c.cord[3])){
			std::cout<<"the figure is not a rectangle\n";
		}
                return out;
        }

class square : public Figure { //XD public figure
        public:
        square():Figure(4){
        }
};
        std::istream & operator >> (std::istream & out, square &c) {
                for(int ani=0;ani<c.verNum;ani++){
                        out >>c.cord[ani];
                }
                if(!(isParallel(c.cord[0],c.cord[1],c.cord[2],c.cord[3])&&isParallel(c.cord[1],c.cord[2],c.cord[3],c.cord[0]))){
                        std::cout<<"the figure is not a parallelogram\n";
                }
                if(dist(c.cord[0],c.cord[2])!=dist(c.cord[1],c.cord[3])){
                        std::cout<<"the figure is not a rectangle\n";
                }
		if(dist(c.cord[0],c.cord[1])!=dist(c.cord[2],c.cord[3])){
                        std::cout<<"the figure is not a square\n";
                }
                return out;
        }


        std::ostream& operator << (std::ostream & out, Figure &c) {
                for(int arei=0;arei<c.verNum;arei++){
                        out<<c.cord[arei]<<"\n";
                }
                return out;
        }



using namespace::std;

int main(){
	vector<Figure*> arr;
	trap*a;
	rectangle*b;
	square*c;
	char fgt;
	int len;
	cin>>len;
	for(int i=0;i<len;i++){
		cin>>fgt;
		if(fgt=='t'){
			a=new trap;
			cin>>*a;
			arr.push_back(a);
		}
		else if(fgt=='r'){
			b=new rectangle;
			cin>>*b;
			arr.push_back(b);
		}
                else if(fgt=='s'){
                        c=new square;
                        cin>>*c;
                        arr.push_back(c);
		}
		else{
			i--;
			cout<<"please specify what figure you are inputting: t for trapezoid, r for rectangle and s for square.\n";
		}
	}
	for(int i=0;i<len;i++){
		cout<<*arr[i]<<"\n";
	}
	int dl,dt;
	cout<<"\n";
	cin>>dl;
	for(int i=0;i<dl;i++){
		cin>>dt;
		if(dt<len){
			arr.erase(arr.begin()+dt);
			len--;
		}
	}
	for(int i=0;i<len;i++){
                cout<<*arr[i]<<"\n";
        }
	double surf;
	for(int i=0;i<len;i++){
		surf+=arr[i]->figArea();
		cout<<arr[i]->finCenter()<<"\n";
	}
	cout<<"Sum of all surfaces is "<<surf<<"\n";
	/*rectangle testo;
//	cout<<"input rectangle\n";
	cin>>testo;
//	cout<<"input yes\n";
	cout<<testo<<"\n";*/
	return 0;
}
