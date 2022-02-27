import java.util.List;
import java.util.ArrayList;

public class Point {
    List<Rect> arrayRec; // guarda rec adjacentes naquele ponto
    int x, y;
    boolean flagvisitado;
    boolean flagGuard;
    int id; // id vertices
    //int custo;
    Point() {
        x = y = 0;
        id = 0;
        arrayRec = new ArrayList<Rect>();
        flagGuard = false;
        flagvisitado = false;
    }

    Point(int x0, int y0) {
        arrayRec = new ArrayList<Rect>();
        flagGuard = false;
        flagvisitado = false;
        x = x0;
        y = y0;
    }

    public String toString() {
        return "(" + x + "," + y + ")";
    }
    public String imprime(){
        return "(" + id + ")";
    }
}