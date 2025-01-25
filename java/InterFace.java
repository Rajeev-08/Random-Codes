interface Operation {
    void add();
    void mul();
    void sub();
    void div();
}
abstract class Add implements Operation{
   public  void add(){
        System.out.println("5+2 =7");
    }
}
class Oter extends Add{
   public  void sub(){
        System.out.println("5-2=3");
    }
   public  void mul(){
        System.out.println("5*2=10");
    }
   public  void div(){
        System.out.println("10/2=5");
    }
}
public class  B{
    public static void main(String[] args) {
        Oter o=new Oter();
        o.add();
        o.div();
        o.mul();
        o.sub();
    }
    
}