import java.io.*;
import java.util.Scanner;
class T{
  public static void main(String[] args) {
    try{
    File f=new File("n.txt");
    Scanner s=new Scanner(f);
      while(s.hasNext()){
        System.out.println(s.next());
      }


  }catch(Exception e){
    System.out.println(e);
  }
}
}
