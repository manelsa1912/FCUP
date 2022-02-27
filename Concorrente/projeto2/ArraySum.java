import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;

class Result {
  private int value;
  public synchronized void addNum(int num) { value += num; }
  public synchronized int getValue()   { return value; } 
}

public class ArraySum {
  
  // Programa de teste.
  public static void main(String[] args) throws InterruptedException{
    int size = args.length >= 1 ? 
      Integer.parseInt(args[0]) : 10000;
    int numberOfThreads = args.length >= 2 ?
      Integer.parseInt(args[1]) : 2;

    int[] array = buildArray(size);
    
    long t;
    int sum;
    
    // Soma sequencial (sem multi-threading).
    t = System.currentTimeMillis();
    sum = sumArraySeq(array);
    t = System.currentTimeMillis() - t;
    System.out.printf("sumArraySeq| Result=%d in %d ms%n", sum, t);

    // Soma com múltiplas threads - versão 1
    t = System.currentTimeMillis();
    sum = sumArrayMT1(numberOfThreads, array);
    t = System.currentTimeMillis() - t;
    System.out.printf("sumArrayMT1 | Result=%d in %d ms%n", sum, t);
 
    // Soma com múltiplas threads - versão 2
    t = System.currentTimeMillis();
    sum = sumArrayMT2(numberOfThreads, array);
    t = System.currentTimeMillis() - t;
    System.out.printf("sumArrayMT2 | Result=%d in %d ms%n", sum, t);

    // Soma com múltiplas threads - versão 3
    t = System.currentTimeMillis();
    sum = sumArrayMT3(numberOfThreads, array);
    t = System.currentTimeMillis() - t;
    System.out.printf("sumArrayMT3 | Result=%d in %d ms%n", sum, t);
  }

  static int[] buildArray(int size) {
    int[] array = new int[size];
    Random r = new Random(0);
    for (int i = 0; i < size; i++) {
      array[i] = -100 + r.nextInt(201); // -100 to 100
    }
    return array;
  }

  // Soma sequencial.
  static int sumArraySeq(int[] array) {
    int sum = 0;
    for (int i = 0; i < array.length; i++) {
      sum += array[i];
    }
    return sum;
  }

  // Soma com múltiplas threads - versão 1. 
  static int sumArrayMT1(int numberOfThreads, int[] array) throws InterruptedException{
    Result r = new Result();
    Thread[] t = new Thread[numberOfThreads];
    int n= array.length/numberOfThreads;
    int nRest = array.length%numberOfThreads;
    int aux=0;
    
    for(int i=0;i<numberOfThreads;i++){
      int index=i;
      final int start = index * n + aux;
      int end;
      if(nRest!=0){
        end = start + n+1;
        nRest--;
        aux++;
      }
      else end = start + n;  
      final int end2=end;

      t[i] = new Thread(() -> {     
        for(int j=start;j<end2;j++){
          r.addNum(array[j]);
        }
      });
      
      t[i].start();
    }
    
    for(int i=0;i<t.length;i++){
      t[i].join();
    }
    return r.getValue();
  }

  // Soma com múltiplas threads - versão 2.
  static int sumArrayMT2(int numberOfThreads, int[] array) throws InterruptedException {
    AtomicInteger r = new AtomicInteger();
    Thread[] t = new Thread[numberOfThreads];
    int n= array.length/numberOfThreads;
    int nRest = array.length%numberOfThreads;
    int aux=0;
    
    for(int i=0;i<numberOfThreads;i++){
      int index=i;
      final int start = index * n + aux;
      int end;
      if(nRest!=0){
        end = start + n+1;
        nRest--;
        aux++;
      }
      else end = start + n;  
      final int end2=end;

      t[i] = new Thread(() -> {     
        for(int j=start;j<end2;j++){
          r.addAndGet(array[j]);
        }
      });
      
      t[i].start();
    }
    
    for(int i=0;i<t.length;i++){
      t[i].join();
    }
    return r.get();
  }
  

  // Soma com múltiplas threads - versão 3.
  static int sumArrayMT3(int numberOfThreads, int[] array) throws InterruptedException{
    int[] parcialSum =new int[numberOfThreads];
    Thread[] t = new Thread[numberOfThreads];
    int n= array.length/numberOfThreads;
    int nRest = array.length%numberOfThreads;
    int aux=0;
    
    for(int i=0;i<numberOfThreads;i++){
      int index=i;
      final int start = index * n + aux;
      int end;
      if(nRest!=0){
        end = start + n+1;
        nRest--;
        aux++;
      }
      else end = start + n;  
      final int end2=end;

      t[i] = new Thread(() -> {     
        for(int j=start;j<end2;j++){
          parcialSum[index]+=array[j];
        }
      });
      
      t[i].start();
    }
    
    int sum=0;
    for(int i=0;i<t.length;i++){
      t[i].join();
      sum+=parcialSum[i];
    }
      return sum;
  }
}
