import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;

public class Annealing {
    public int heuristica(NodePoint node, List<Rect> arrayRecGlobal) {
        int custo;
        int g = node.nivel;
        int f = arrayRecGlobal.size() - node.Rectangulos.size();
        custo = g + f * (2 * arrayRecGlobal.size() + 3);
        return custo;
    }

    Pesquisas pesquisas = new Pesquisas();
    public NodePoint retornaValor(int rand,Queue<NodePoint> fila){
        NodePoint p = fila.peek();
        while(rand > 0){
            p = fila.remove();
            rand--;
        }
        return p;
    }
    public /*List<Point> */ void simulatedAn(List<Rect> arrayRecGlobal, List<Point> arrayPoints) {
        Random random = new Random();
        List<Point> solution = new ArrayList<Point>();
        double fx, fy;
        double delta;
        Queue<NodePoint> fila = new LinkedList <NodePoint>();
        List<NodePoint> lista;
        NodePoint p;
        NodePoint raiz = new NodePoint(arrayPoints, arrayPoints.size());
        List<Point> melhor = arrayPoints;
        int k=0;
        
        fila.add(raiz);

        lista = raiz.gerarFilhos(arrayPoints);
        fx = heuristica(raiz, arrayRecGlobal);
        System.out.println("heuristica fx:" + fx);
        double T= fx;
        double T0 = T;

        while(T > 0){
            for(int i=1; i < k;i++){
            /*if(T==0){
                solution.add(raiz.Ponto);
                //return solution;
            }*/
            for (NodePoint ponto : lista) {
                fila.add(ponto);
            } 
            int rand2 = random.nextInt(fila.size());
            p = retornaValor(rand2,fila); //norandom
            
            fy = heuristica(p, arrayRecGlobal);
            delta = fy - fx;

            if (delta < 0 /*||Math.exp(-delta / fx)>=random.nextDouble() * 1D*/) { //bom move
                raiz = p;
               solution.add(raiz.Ponto);
            } 

           else{
                double rand = random.nextDouble() * 1D;
                double prob = Math.exp(-delta / T);
                if (rand < prob) {
                    raiz = p;
                    //solution.add(p.Ponto);
                }
            }
            /*lista = p.gerarFilhos(arrayPoints);
            for (NodePoint ponto : lista) {
                fila.add(ponto);
                System.out.println("Pontos filhos" + ponto.Ponto.id);
            }*/
            k = k + 1;
            T = T0/Math.log(1+k);
            
 
        }
        if(solution.size() < melhor.size()) {
            melhor = solution;
        }
         //return melhor;
         for(Point pp: melhor){
               System.out.println("guardas" + pp.toString());
         }
           // return solution;
    
    }
}}