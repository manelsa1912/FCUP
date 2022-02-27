public class teste2 {
    // Desenha uma linha de n caracteres onde:
    // - o primeiro e o último caracteres são o caracter da variável 'a'
    // - todos os outros caracteres são o caracter da variável 'b'
    static void line(char c, char b, int n) {
	System.out.print(c);
	for (int i=1; i<=n-2; i++)
	    System.out.print(b);
	System.out.println(c);
    }

    // O procedimento executado inicialmente é sempre o main
    public static void main(String[] args) {	
	line('+','-',5);
	for(int i=0;i<3;i++)
	    line('*','~',5);
	line('+','-',5);
    }
}
