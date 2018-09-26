#include<stdio.h>   
#include<time.h>   

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

	printf("%f\n", s1);
	printf("%f\n", s4);
	printf("%f\n", s5);
	printf("%f\n", s6);
	printf("%f\n", pi);
		
	char hexa[6];

	for(int i = 0; i < 6; i++){
		hexa[i] = 'A' + i;
	}

	
	while(simplify(pi) != 0) {
		pi = pi*16;
		if((int)pi >= 10) {	
			printf("%c", hexa[(int)pi-10]);
		} else {
			printf("%d", (int)pi);
		}
		pi = simplify(pi);
	}
	printf("\n");


	end = clock();   

    float diff = ((float)(end - start));   
  
	printf("C: %.6f sec %dd mellett.\n", diff / CLOCKS_PER_SEC, d);
 
    return 0;   
}