#include <iostream>   
#include <time.h>   

using namespace std;

double simplify(double db) {
	if(db < 0) {
		return db - (int)db+1;
	} else {
		return db - (int)db;
	}
}
		
double modulo(double b, double n, double k) {
		
	double t = 1;
	double r = 1;
			
	while(t <= n) {
		t = t * 2;
	}
	
	for(;;) {

		if(n >= t) {
			r = (long int)(b * r) % (long int)k;
			n= n - t;
		}
		t = t / 2;
		
		if(t >= 1) {
			r = (long int)(r*r) % (long int)k;
		} else {
			break;
		}
	}
	return r;
}	

double s_solve(double d, double num) {
		
	double sum = 0.0;
	
	for(int i = 0; i <= d; i++) {
		sum += modulo(16, (d-i), 8*i+num) / (8*i + num);
	}
	
	return sum ;
}

int main(){  
 
	clock_t start, end;  
	start = clock();   

	int d = 10;
		
	double s1 = s_solve(d, 1);

	double s4 = s_solve(d, 4);
	double s5 = s_solve(d, 5);
	double s6 = s_solve(d, 6);
	
	s1 = simplify(s1);
	s4 = simplify(s4);
	s5 = simplify(s5);
	s6 = simplify(s6);
		
	double pi = 4*s1 -2*s4 - s5 -s6;
		
	pi = simplify(pi);

	cout << s1 << endl << s4 << endl << s5 << endl << s6 << endl;
		
	char hexa[6];

	for(int i = 0; i < 6; i++){
		hexa[i] = 'A' + i;
	}

	
	while(simplify(pi) != 0) {
		pi = pi*16;
		if((int)pi >= 10) {	
			cout << hexa[(int)pi-10];
		} else {
			cout << (int)pi;
		}
		pi = simplify(pi);
	}
	cout << endl;


	end = clock();   

    float diff = ((float)(end - start));   
  
	cout << "C: " << diff/CLOCKS_PER_SEC << " sec " << d << "d mellett." << endl;

    return 0;   
}