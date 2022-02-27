import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Comparator;

class funcComparator implements Comparator<NodePoint> { // comparar o nr de vertices do rect
    public int compare(NodePoint p1,NodePoint p2) {
        return p1.heuristicaC- p2.heuristicaC; // crescente
    }

}
public class Ils {
    PriorityQueue<NodePoint> fila;
    Comparator<NodePoint> comparator;
    Pesquisas pesquisas = new Pesquisas();

    public int heuristica(NodePoint node,List<Rect> arrayRecGlobal){
        int custo;
        int g=node.nivel;
        int f= arrayRecGlobal.size() - node.Rectangulos.size(); ///nr rects que nao podem ser visitados
        custo = g+f*(2*arrayRecGlobal.size()+3);
        return custo;
    }

    public void ils(List<Rect> arrayRecGlobal, List<Point> arrayPoints){
        comparator = new funcComparator();
        fila = new PriorityQueue<>(comparator);
        
        NodePoint raiz = new NodePoint(arrayPoints,arrayPoints.size());
        
        List<NodePoint> lista1 = raiz.gerarFilhos(arrayPoints);
        for (NodePoint p : lista1) {
            p.heuristicaC = heuristica(p, arrayRecGlobal);
                fila.add(p);
        }

        while(!fila.isEmpty()){
            
            NodePoint temp = fila.remove();
            
            if(pesquisas.verificaSolucao(temp,arrayRecGlobal.size())){
                List<Point> solution = new ArrayList<Point>();
                solution.add(temp.Ponto);
                NodePoint aux = temp.Pai;
                
                while (aux.Pai != null) {
                    solution.add(aux.Ponto);
                    aux = aux.Pai;
                    
                }
                for (Point p : solution)
                System.out.println("guardas" + p.toString());
                return;
            }
                
            List<NodePoint> lista = temp.gerarFilhos(arrayPoints);

            for (NodePoint p : lista) {
                p.heuristicaC = heuristica(p, arrayRecGlobal);
                fila.add(p);
                System.out.println("Pontos filhos" + p.Ponto.id);
            }
            
        }

    }

    public List<Point> ilsRandom(List<Rect> arrayRecGlobal, List<Point> arrayPoints, int idrand){
        comparator = new funcComparator();
        fila = new PriorityQueue<>(comparator);
        List<Point> solution = new ArrayList<Point>();

        NodePoint raiz = new NodePoint(arrayPoints,arrayPoints.size());
        NodePoint primeiro = new NodePoint(arrayPoints.get(idrand),raiz);
        System.out.println("primeiro no" + primeiro.Ponto.toString());
        primeiro.addRectangulos();
        System.out.println("retangulos no" + primeiro.Rectangulos.size());
       // List<NodePoint> lista1 = primeiro.gerarFilhos(arrayPoints);
       /* for (NodePoint p : lista1) {
            p.heuristicaC = heuristica(p, arrayRecGlobal);
                fila.add(p);
        }*/
        fila.add(primeiro);

        while(!fila.isEmpty()){
            
            NodePoint temp = fila.remove();
            
            if(pesquisas.verificaSolucao(temp,arrayRecGlobal.size())){
                //System.out.println("custo ponto" + temp.heuristicaC);
               // System.out.println("tamanho rec visitados" + temp.Rectangulos.size());
               // List<Point> solution = new ArrayList<Point>();
                solution.add(temp.Ponto);
                NodePoint aux = temp.Pai;
                
                while (aux.Pai != null) {
                    solution.add(aux.Ponto);
                    aux = aux.Pai;
                    
                }
            
                return solution;
            }
            List<NodePoint> lista = temp.gerarFilhos(arrayPoints);

            for (NodePoint p : lista) {
                p.heuristicaC = heuristica(p, arrayRecGlobal);
                fila.add(p);
                //System.out.println("Pontos filhos" + p.Ponto.id);
            }
            
        }
        return solution;
    }
}