    import java.io.*;
    import java.util.*;
    
    class Letra implements Comparable<Letra> {
        public char letra;
        public int contagem;
        public int posicao;

    public Letra(char l, int n, int pos){
        letra = l;
        contagem = n;
        posicao = pos;
    }
    @Override
    public int compareTo(Letra a) {
        if(a.contagem < contagem)
            return -1;

        if(a.contagem > contagem)
            return 1;
        else{
            if(  posicao>a.posicao)
                return 1;
            return -1;
        }
        }
    
    }
    public class daa009 {
        public static void main(String args[]) {
            Scanner stdin = new Scanner(System.in);
            Letra letra[] =  new Letra[26];
            for (int i = 0; i <26; i++)
                letra[i] = new Letra((char)('A'+i), 0, -1);
            //ler fragmento adn
            String adn = stdin.nextLine();
            for(int i=0; i < adn.length();i++){
                int l= adn.charAt(i) -'A';
                //System.out.println(l);
                letra[l].contagem ++;
                if(letra[l].contagem ==1)
                    letra[l].posicao =i;
            }
            Arrays.sort(letra);
            for(int i=0; i < 26; i++){
                if(letra[i].contagem>=1)
                System.out.println(letra[i].letra + " " +  letra[i].contagem);
            }
        
        }
    }
