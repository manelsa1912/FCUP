import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NodePoint {
    List<NodePoint> Filhos;
    List<Integer> Rectangulos;
    Point Ponto;
    NodePoint Pai;
    int nivel;
    int heuristicaA;//a*
    int heuristicaB; //para o bnb
    int heuristicaC; //ils
    boolean guardas[];
    int size;

    // Construtor da raiz, recebe todos os verts do input txt
    // Rceber na mesma points e transformar em node(ou criar funçao para tal)
    NodePoint(List<Point> Filhos, int size) {
        this.Ponto = new Point();
        this.Filhos = new ArrayList<NodePoint>();
        this.Rectangulos = new ArrayList<Integer>();
        this.Pai = null;
        this.nivel = 0;
        this.heuristicaA=0;
        this.heuristicaB=0;
        this.size = size;
        this.guardas = new boolean[size];
        Arrays.fill(this.guardas,false);

    }

    // Construtor de no recebe guardas ja colocadas
    NodePoint(Point ponto, NodePoint pai) {
        this.Ponto = ponto;
        this.Pai = pai;
        this.Rectangulos =  new ArrayList<Integer>();
        this.Filhos = new ArrayList<NodePoint>();
        this.nivel= pai.nivel+1;
        this.heuristicaA=0;
        this.heuristicaB=0;
        this.guardas = pai.guardas;
        this.size = pai.size;
        this.guardas[this.Ponto.id] =true;
    }

    // Insere os Rectangulos todos do ponto no construtor
    public void addRectangulos() { // função correta*****1000000000000%
        if (this.Ponto.arrayRec == null)
            return;
        for (Rect r : this.Ponto.arrayRec) {
            if (!(this.Rectangulos.contains(r.idRec)))
                this.Rectangulos.add(r.idRec);
        }
        NodePoint aux = this.Pai;
        while(aux!=null){
            for(int i: aux.Rectangulos){
                if (!(this.Rectangulos.contains(i)))
                    this.Rectangulos.add(i);
            }
            aux = aux.Pai;
        }
    }


    public boolean rectsComum(NodePoint p1, Point p2) { // biens
        for (Rect r : p2.arrayRec) {
            if (p1.Rectangulos.contains(r.idRec))
                return true;
        }
        return false;
    }

    public boolean utilizados(Point p) {
        if (this.Ponto.equals(p))
            return true;
        NodePoint np = this.Pai;
        while (np != null) {
            if (np.Ponto.equals(p))
                return true;
            np = np.Pai;
        }
        return false;
    }


    public List<NodePoint> gerarFilhos(List<Point> arrayPoints) {
       
        for (Point p : arrayPoints) {
            if ((!this.utilizados(p)) && (!rectsComum(this, p))) {
                NodePoint n = new NodePoint(p, this);
                n.addRectangulos();
                this.Filhos.add(n);
            }
        }

        return this.Filhos;
    }
}