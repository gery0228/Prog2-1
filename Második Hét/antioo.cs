using System;

public class Anti_oo{

	public static void Main(){

		long start = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;

		int d = 100000000;
		
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

		Console.WriteLine(s1);
		Console.WriteLine(s4);
		Console.WriteLine(s5);
		Console.WriteLine(s6);
		Console.WriteLine(pi);
		
		String[] hexa = {"A", "B", "C", "D", "E", "F"};
		
		while(simplify(pi) != 0) {
			pi = pi*16;
			if((int)pi >= 10) {
				Console.Write(hexa[(int)pi - 10]);
			} else {
				Console.Write((int)pi);
			}
			pi = simplify(pi);
		}

		long end = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;
		Console.WriteLine("\nC#: " + (double)(end-start)/1000 + " sec " + d + "d mellett.");
	}

	public static double simplify(double db) {
		if(db < 0) {
			return db - (int)db+1;
		} else {
			return db - (int)db;
		}
	}

	public static double s_solve(double d, double num) {
		
		double sum = 0.0;
		
		for(int i = 0; i <= d; i++) {
			sum += modulo(16, (d-i), 8*i+num) / (8*i + num);
		}
		
		return sum ;
	}
	
	public static double modulo(double b, double n, double k) {
		
		double t = 1;
		double r = 1;
				
		while(t <= n) {
			t = t * 2;
		}
		
		while(true) {
			if(n >= t) {
				r = (b * r) % k;
				n= n - t;
			}
			t = t / 2;
			
			if(t >= 1) {
				r = (r*r) % k;
			} else {
				break;
			}
		}
		return r;
	}	
}