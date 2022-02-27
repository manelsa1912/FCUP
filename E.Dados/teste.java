// Uma classe muito simples que usa um ciclo para imprimir numeros entre 1 e n

// O ficheiro tem de ter o mesmo nome da classe + a extensão '.java'
public class teste{
    public static void main(String[] args) {
	int n = 1000000; // limite dos numeros
	int s = 0;
	
	System.out.print("Numeros de 1 a " + n + ": "); // + é o operador de concatenação de strings
	for (int i=1; i<n; i++){
	    s = s + i;
	    System.out.print(i+",");}

 s=s+n;
 System.out.println(n);
 System.out.print("Soma = ");
 System.out.println(s);


    }
}
