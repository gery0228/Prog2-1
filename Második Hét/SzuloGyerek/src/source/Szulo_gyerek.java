package source;

public class Szulo_gyerek {

	class Jarmu{
		
		String rendszam;
		String marka;
                String allohelyek;
		
		Jarmu(){
			rendszam = "ABC-123";
			marka = "Suzuki";
                        allohelyek="170";
		}
	}
	
	class Autobusz extends Jarmu{
		
			
	}
	
	public static void main(String[] args) {
		
		Szulo_gyerek sz_gy = new Szulo_gyerek();
		Jarmu busz = sz_gy.new Autobusz();
		
		System.out.println(busz.marka);
		System.out.println(busz.rendszam);
		System.out.println(busz.allohelyek);	
	}
}