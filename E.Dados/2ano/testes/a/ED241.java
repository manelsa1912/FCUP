import java.util.Scanner;

public class ED241 {
   public static void main(String[] args) {
        Scanner in= new Scanner(System.in);

        
        BSTree<String> submissoes= new BSTree<String>(); 
        BSTMap<String,Integer> nsubmis = new BSTMap<>();  
        BSTMap<String,Integer> dado = new BSTMap<>();

        int flag=in.nextInt();
        int nsubmissoes=in.nextInt();
        
        
        String l=in.nextLine();

       
        for(int i=0; i<nsubmissoes;i++){
            String line=in.nextLine(); //linha
            String[] dados=line.split(" ");
            
            
            if(flag==1){
                  submissoes.insert(dados[1]);
        

        if(flag==1){
            System.out.println(submissoes.numberNodes());
        }
     
   }
   }
}
}
