import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class solutionComparator implements Comparator<NodePoint> { // comparar o nr de vertices do rect
    public int compare(NodePoint p1, NodePoint p2) {
        return p2.heuristicaA - p1.heuristicaA; // decrescente
    }
}

public class AEstrela {
    Pesquisas pesquisas;
    PriorityQueue<NodePoint> fila;
    Point p;
    Comparator<NodePoint> comparator;
    AEstrela() { // construtor vazio77
        p= new Point();
        pesquisas = new Pesquisas();
        comparator= new solutionComparator();
        fila = new PriorityQueue<>(comparator);
    }
 
public int heuristica(NodePoint np, List<Rect> arrayRecGlobal){
    int solucao=0;
      solucao = np.Rectangulos.size();
   /*   if( arrayRecGlobal.size()%3 == 0) 
      solucao = arrayRecGlobal.size()/3;
  else
      solucao = arrayRecGlobal.size()/3 +1;*/
   return solucao;
}

public void a_estrela(List<Rect> arrayRecGlobal, List<Point> arrayPoints) {
    NodePoint raiz = new NodePoint(arrayPoints,arrayPoints.size());
  
    fila.add(raiz);
    while (!fila.isEmpty()) {
        NodePoint temp = fila.remove();

        if (pesquisas.verificaSolucao(temp, arrayRecGlobal.size())) {
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
            p.heuristicaA = heuristica(p, arrayRecGlobal);
            fila.add(p);
            System.out.println("Pontos filhos" + p.Ponto.id);
        }

    }
}

}