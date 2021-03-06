import java.util.Scanner;

class Matrix {
   int data[][]; // os elementos da matriz em si
   int rows;     // numero de linhas
   int cols;     // numero de colunas

   // construtor padrao de matriz
   Matrix(int r, int c) {
      data = new int[r][c];
      rows = r;
      cols = c;
   }
    public static Matrix identity(int n){
	Matrix ident = new Matrix(n, n);
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		if(i==j){
		    ident.data[i][j]=1;}
		else ident.data[i][j]=0;}
	}
	return ident;}


    public Matrix transpose(){
	Matrix trans = new Matrix(cols, rows);
	for(int i=0;i<cols;i++){
	    for(int j=0;j<rows;j++){

		trans.data[i][j]=this.data[j][i];}
	}
	return trans;
    }

    public Matrix sum (Matrix m);

		

    public Matrix multiply(Matrix m){
	return m;}
    
	

   // Ler os rows x cols elementos da matriz
   public void read(Scanner in) {
      for (int i=0; i<rows; i++)
         for (int j=0; j<cols; j++)
            data[i][j] = in.nextInt();
   }

   // Representacao em String da matriz
   public String toString() {
      String ans = "";
      for (int i=0; i<rows; i++) {
         for (int j=0; j<cols; j++)
            ans += data[i][j] + " ";
         ans += "\n";
      }
      return ans;
   }   
}
