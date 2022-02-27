java.util.Scanner;

public class ED198{
    public static void main(){
	
        int maxSoFar = v[0];
      	for (int i=0; i<n; i++) // Todas as posicoes iniciais possiveis

	    for (int j=i; j<n; j++) {
		int sum = 0;

		for (int k=i; k<=j; k++) // Calcular soma entre posicoes i e j

		    sum += v[k];

		System.out.println("Soma entre " + i + " e " + j + " = " + sum);

		if (sum > maxSoFar) maxSoFar = sum;

	    }

	System.out.println(maxSoFar);
	
    }
}
