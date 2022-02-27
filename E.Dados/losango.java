import java.util.Scanner;

public class losango {
 
	static void losango(int size){
 
	int n = (size/2);
 int aux1 = n, aux2 = 1;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<aux1;j++){
			
			System.out.print(".");
			}

		for(int j=1;j<=aux2;j++){
				System.out.print("#");
		}
		aux2+=2;
		
		for(int j=0;j<aux1;j++){
			
			System.out.print(".");
			}
  
   System.out.println();
		
  aux1--;
	
	}

		for(int f=0;f<size;f++)
		{
			System.out.print("#");
			}
		
	System.out.println();

 aux1=1;
	aux2-=2;

	for(int i=0;i<n;i++){
		
		for(int j=aux1;j>0;j--){
			
			System.out.print(".");
			}

		for(int j=1;j<=aux2;j++){
				System.out.print("#");
		}
		aux2-=2;
		
		for(int j=aux1;j>0;j--){
			
			System.out.print(".");
			}
  
   System.out.println();
		
  aux1++;
	
	}

	
	
	 	

  

	




	

				}

    
public static void main(String[] args)
{
    Scanner stdin=new Scanner(System.in);
    int size=stdin.nextInt();
    losango(size);
}
}
