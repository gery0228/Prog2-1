package source;

public class Liskov {

	class Emberke{
		String leanykori_nev;
		
		Emberke(String str){
			leanykori_nev = str + "...";
		}
	}

	class Ferfi extends Emberke{

		Ferfi(String str) {
			super(str);
		}	
	}
	
	class No extends Emberke{

		No(String str) {
			super(str);
		}	
	}
	
	public static void main(String[] args) {
		Liskov lis = new Liskov();
		
		No no = lis.new No("");
		Ferfi ffi = lis.new Ferfi("");
		
		System.out.println(no.leanykori_nev);
		System.out.println(ffi.leanykori_nev);
	}
}