import java.io.*;
import java.util.Scanner;
class FileStringSearch{
  public static void main(String[] args) {
    Scanner s=new Scanner(System.in);
    String input=s.nextLine();
    int count=0;
    try{
    File f=new File("n.txt");
    FileWriter fw=new FileWriter(f);
    fw.write(input);    
fw.close();
  }catch(Exception e){
    System.out.println(e);
  }
 
}
}
