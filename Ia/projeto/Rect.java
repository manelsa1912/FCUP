import java.util.List;
import java.util.ArrayList;

public class Rect {
    int idRec;
    boolean flagRec; // ver se ja esta visitido
    List<Integer> arrayIdVert = new ArrayList<>(); // id dos pontos que pertecem a retangulo

    Rect() {
        this.idRec = 0;
        this.flagRec = false;
    }

    public int imprimir() {
        return idRec;
    }
}