import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Bnb {
    Pesquisas pesquisas;

    Bnb() {
        pesquisas = new Pesquisas();
    }

    public void bnb(List<Rect> arrayRecGlobal, List<Point> arrayPoints) {
        Stack<NodePoint> pilha = new Stack<NodePoint>();
        NodePoint raiz = new NodePoint(arrayPoints,arrayPoints.size());
        pilha.push(raiz);

        while (!pilha.isEmpty()) {

            NodePoint temp = pilha.pop();

            if (verificaSolucao(temp, arrayRecGlobal.size())) {
                List<Point> solution = new ArrayList<Point>();
                solution.add(temp.Ponto);
                NodePoint aux = temp.Pai;
                while (aux.Pai != null) {
                    solution.add(aux.Ponto);
                    aux = aux.Pai;
                }
                for (Point p : solution)
                    System.out.println("guardas" + p.toString());
                
            }
            if (temp.nivel < nivel) {
                List<NodePoint> lista = temp.gerarFilhos(arrayPoints);

                // System.out.println("ponto pai " + temp.Ponto.toString());
                for (NodePoint p : lista) {
                    pilha.push(p);
                    
                }
            }

        }
        
    }
}