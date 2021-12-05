#include <iostream>
#include <math.h>
using namespace std;

int main(){
	double a,b,c,temp,delta,x;
	cout<<"Inserire Coefficiente di secondo grado: ";
	cin>>a;
	cout<<"Inserire Coefficiente di primo grado: ";
	cin>>b;
	cout<<"Inserire Termine noto: ";
	cin>>c;
	
	if(a==0&&b==0&&c==0){
		cout<<"Inserire i valori\n";
		main();
	}
	if(a==0){
		cout<<"X= "<<c*-1/b;
		return 1;
	}
	if(c==0){
		cout<<"X1= 0\t"<<"X2= "<<b*-1/a;
		return 1;
	}
	if(b==0){
		if((a*c)>0){
			cout<<"L'equazione non ha soluzioni reali";
			return 1;
		}
		else{
			x=sqrt(c*-1/a);
			cout<<"X1= "<<x<<"\t"<<"X2= "<<x*-1;
			return 1;
		}
	}
	delta=b*b-(4*a*c);
	if(delta<0){
		cout<<"L'equazione non ha soluzioni reali";
		return 1;
	}
	if(delta==0){
		b=b*-1;
		cout<<"X= "<<b*-1/2*a;
		return 1;
	}
	if(delta>0){
		a=2*a;
		x=(b*-1+sqrt(delta))/a;
		cout<<"X1= "<<x<<"\t";
		x=(b*-1-sqrt(delta))/a;
		cout<<"X2= "<<x<<"\t";
		
	}
	return 0;
}
