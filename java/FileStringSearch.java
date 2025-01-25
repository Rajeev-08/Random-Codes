import java.io.*;
import java.util.Scanner;
class FileScanner{
  public static void main(String[] args) {
    String key="you";
    int count=0;
    try{
    File f=new File("n.txt");
    Scanner s=new Scanner(f);
      while(s.hasNext()){
        if(key.equals(s.next())){
          count++;
        }
      }
      System.out.println(count);
    

  }catch(Exception e){
    System.out.println(e);
  }
 
}
}
