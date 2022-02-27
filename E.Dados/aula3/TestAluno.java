// Uma classe simples para representar um aluno
class Aluno {
   // Atributos da classe (variáveis para conter informação)
   String nome;
   int numero;

  Aluno(String n, int mec) {
   nome = n;
   numero = mec;
} // Construtor "padrão"
   Aluno() {
      nome   = "indefinido";
      numero = -1;
   }
    public String toString() {
   return "(" + nome + "," + numero + ")";
}
}

// Classe principal contendo o main para testar a classe Aluno
public class TestAluno {
   public static void main(String[] args) {

      int n = 3;
Aluno[] v = new Aluno[n];
for (int i=0; i<n; i++)
   System.out.println("v[" + i + "] = " + v[i]);
v[0].nome = "Pedro";

for (int i=0; i<n; i++) v[i] = new Aluno();



      Aluno a = new Aluno();
      Aluno b = new Aluno();
      Aluno c = b;
      Aluno d = new Aluno();
      Aluno e = new Aluno("Manuel", 201506234);
      Aluno f = new Aluno("Maria", 201805273 ); 
      
      System.out.println("a.nome = " + a.nome);
      System.out.println("a.numero = " + a.numero);
      System.out.println("a="+a);
      b.nome = "modificado";
      System.out.println("b = " + b);
      System.out.println("c = " + c);
      System.out.println("d = " + d);
      System.out.println("e = " + e);
      System.out.println("f = " + f);
   }
}
