import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Rec {
   public Node node;// = new Node();
   public NodePoint nodepoint;
   public Pesquisas pesquisa;// = new Pesquisas();
   public List<Point> arrayPoints;// = new ArrayList<>();
   public List<Rect> arrayRecGlobal;// = new ArrayList<>(); // guarda rec adjacentes naquele ponto
   public List<NodePoint> arrayNodePoints;

   Rec() {
      this.node = new Node();
      this.pesquisa = new Pesquisas();
      this.arrayPoints = new ArrayList<>();
      this.arrayRecGlobal = new ArrayList<>();
      this.arrayNodePoints = new ArrayList<>();
   }

   public void CriarCoord(Rect r, int idVert, int x, int y) {
      // verificar se ponto existe
      // if (existVert(r, arrayPoints, x, y))
      // return;

      Point p = new Point(x, y);
      p.id = idVert;
      arrayPoints.add(p);
      r.arrayIdVert.add(p.id); // dar array dos vert do rec o id do vert
      p.arrayRec.add(r); // dar ao array dos retangulos o rec
   }

   public static boolean existVert(Rect r, List<Point> arrayPoints, int x, int y) {
      for (int i = 0; i < arrayPoints.size(); i++) {
         if ((arrayPoints.get(i).x) == x && (arrayPoints.get(i).y) == y)
            // adicionar o rec ao arrayrec do ponto
            return true;
      }
      return false;
   }

   public int buscarVert(int x, int y) {
      for (int i = 0; i < arrayPoints.size(); i++) {
         if ((arrayPoints.get(i).x) == x && (arrayPoints.get(i).y) == y)
            return arrayPoints.get(i).id;
      }
      return -1;
   }

   public static void main(String[] args) {
      Rec rec = new Rec();
      AEstrela ae = new AEstrela();
      Bnb bnb = new Bnb();
      Scanner stdin = new Scanner(System.in);
      int map = stdin.nextInt();
      int numRec, idRec, idVert, numCord;
      int auxVert = 0;
      int x, y;
      Random random = new Random(); 
      

      for (int i = 0; i < map; i++) {
         numRec = stdin.nextInt();
         for (int j = 1; j <= numRec; j++) {
            idRec = stdin.nextInt();
            numCord = stdin.nextInt();
            Rect r = new Rect();
            r.idRec = idRec;
            rec.arrayRecGlobal.add(r);
            for (int k = 0; k < numCord; k++) {
               idVert = auxVert; // atribuir id ao par de coordenadas
               x = stdin.nextInt();
               y = stdin.nextInt();
               if (!existVert(r, rec.arrayPoints, x, y)) {
                  rec.CriarCoord(r, idVert, x, y);
                  auxVert++;
               } else {
                  r.arrayIdVert.add(rec.buscarVert(x, y));
                  Point p = rec.arrayPoints.get(rec.buscarVert(x, y));
                  p.arrayRec.add(r); // dar ao array dos retangulos o rec
               }
            }
            /*
             * for (int l = 0; l < r.arrayIdVert.size(); l++) {
             * System.out.println(r.arrayIdVert.get(l) + " " +
             * rec.arrayPoints.get(r.arrayIdVert.get(l)).toString());
             * 
             * }
             */
         }

       //rec.pesquisa.Greedy(rec.arrayPoints);
      //rec.pesquisa.bfs(rec.arrayRecGlobal, rec.arrayPoints);
      //boolean dfs = rec.pesquisa.dfs(rec.arrayRecGlobal, rec.arrayPoints, Integer.MAX_VALUE);
      //rec.pesquisa.idfs(rec.arrayRecGlobal, rec.arrayPoints);
      //ae.a_estrela(rec.arrayRecGlobal, rec.arrayPoints);
      //bnb.bnb(rec.arrayRecGlobal, rec.arrayPoints);
         /*Ils ils = new Ils();
         List<List<Point>> sol = new ArrayList<>();
         ils.ils(rec.arrayRecGlobal,rec.arrayPoints);
         boolean arraybool[] = new boolean[rec.arrayPoints.size()];
         for(int juiz=0;juiz<rec.arrayPoints.size();juiz++){
            int ei=random.nextInt(rec.arrayPoints.size());
            while(arraybool[ei]==true){
               ei=random.nextInt(rec.arrayPoints.size());
            }
            sol.add(ils.ilsRandom(rec.arrayRecGlobal,rec.arrayPoints,ei));
            arraybool[ei]=true;
         }
         int min = 10000000; //tamanho minimo
         int pos = 0, count=0;
         for(List<Point> lista: sol){
            for(Point p: lista){
               System.out.println("lista" + p.toString());
            }
            System.out.println();
            if(lista.size() < min && lista.size()!=0){
               pos = count; //pos do min
               min = lista.size();
            }
            count++;
         }

         for(Point p: sol.get(pos)){
            System.out.println("Guardas" + p.toString());
         }*/

         Annealing anneal = new Annealing();
        ///* List<Point> sol =*/ 
        anneal.simulatedAn(rec.arrayRecGlobal,rec.arrayPoints);
         /*for(Point p: sol){
               System.out.println("guardas" + p.toString());
         }*/
         
      }

      stdin.close();
   }
}