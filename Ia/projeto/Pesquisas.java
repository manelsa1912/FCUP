import java.util.*;

class NodeComparator implements Comparator<Point> { // comparar o nr de vertices do rect
    public int compare(Point p1, Point p2) {
        return p2.arrayRec.size() - p1.arrayRec.size(); // decrescente
    }
}

public class Pesquisas {
    Rec c;
    List<Point> arrayPoints;
    NodeComparator comparator;
    PriorityQueue<Point> fila;
    ArrayList<Rect> recvisitados;
    ArrayList<Integer> Pontosvisitados;
    Point p;
    Rect rec;

    Pesquisas() { // construtor vazio77
        p = new Point();
        comparator = new NodeComparator();
        fila = new PriorityQueue<>(comparator);
        recvisitados = new ArrayList<Rect>();
        Pontosvisitados = new ArrayList<Integer>();
    }

    public void Pvisitados(Rect r, List<Point> arrayPoints) {
        for (int i = 0; i < r.arrayIdVert.size(); i++) {
            int id = r.arrayIdVert.get(i);
            arrayPoints.get(id).flagvisitado = true;
        }
    }

    public void Guarda(Point p, List<Point> arrayPoints) {
        if (p.flagvisitado == false) {
            p.flagGuard = true;
            System.out.println("p guarda" + p.toString());
            for (int i = 0; i < p.arrayRec.size(); i++) {
                Rect r = p.arrayRec.get(i);
                r.flagRec = true;
                Pvisitados(r, arrayPoints);
                recvisitados.add(r);
                p.arrayRec.remove(r);
            }
        }
    }

    public void Greedy(List<Point> arrayPoints) {
        for (int i = 0; i < arrayPoints.size(); i++) {
            p = arrayPoints.get(i);
            fila.offer(p);
        }
        // System.out.println("size arraypo" + arrayPoints.size());
        while (!fila.isEmpty()) {
            p = fila.remove();
            Guarda(p, arrayPoints);
        }
    }

    
    public boolean verificaSolucao(NodePoint no, int i) {
        if (no.Rectangulos.size() == i)
            System.out.println("solucao encontrada no ponto " + no.Ponto.toString());
        return no.Rectangulos.size() == i;
    }

    public void bfs(List<Rect> arrayRecGlobal, List<Point> arrayPoints) {

        Queue<NodePoint> filinha = new LinkedList<NodePoint>();
        NodePoint raiz = new NodePoint(arrayPoints,arrayPoints.size());
        filinha.add(raiz);

        while (!filinha.isEmpty()) {

            NodePoint temp = filinha.remove();

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
                return;
            }
            List<NodePoint> lista = temp.gerarFilhos(arrayPoints);

            // System.out.println("ponto pai " + temp.Ponto.toString());
            for (NodePoint p : lista) {
                filinha.add(p);
                System.out.println("Pontos filhos" + p.Ponto.id);
            }

        }

    }

    public boolean dfs(List<Rect> arrayRecGlobal, List<Point> arrayPoints, int nivel) {
        Stack<NodePoint> pilhinha = new Stack<NodePoint>();
        NodePoint raiz = new NodePoint(arrayPoints,arrayPoints.size());
        pilhinha.push(raiz);

        while (!pilhinha.isEmpty()) {

            NodePoint temp = pilhinha.pop();

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
                return true;
            }
            if (temp.nivel < nivel) {
                List<NodePoint> lista = temp.gerarFilhos(arrayPoints);

                // System.out.println("ponto pai " + temp.Ponto.toString());
                for (NodePoint p : lista) {
                    pilhinha.push(p);
                    System.out.println("Pontos filhos" + p.Ponto.id);
                }
            }

        }
        return false;
    }

    public void idfs(List<Rect> arrayRecGlobal, List<Point> arrayPoints) {
        int nivel = 1;
        boolean encontrouSolucao = dfs(arrayRecGlobal, arrayPoints, nivel);
        while (encontrouSolucao == false) {
            nivel++;
            encontrouSolucao = dfs(arrayRecGlobal, arrayPoints, nivel);
        }
    }

}