public class TestBasicTypes {
   public static void main(String[] args) {
      boolean flag = true;
      char      ch = 'A';
      byte       b = 12;
      short      s = 24;
      int        i = 257;
      long       l = 2147483648L;  // sem a letra e interpretado como int
      float      f = 3.1415f;      // sem a letra e interpretado como double  
      double     d = 2.1828;
      System.out.println("flag = " + flag); 
      System.out.println("ch = "   + ch); 
      System.out.println("b = "    + b); 
      System.out.println("s = "    + s); 
      System.out.println("i = "    + i); 
      System.out.println("l = "    + l); 
      System.out.println("f = "    + f); 
      System.out.println("d = "    + d); 
   }
}