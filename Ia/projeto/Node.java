import java.util.ArrayList;
import java.util.List;

public class Node {
public Rect recPai;
List<Rect> adjacentes = new ArrayList<>();

Node() {
this.recPai = null;
}

String imprime() {
return "" + recPai.idRec;
}

} 