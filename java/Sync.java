class Display{
    public synchronized void print(String s){
        System.out.print("["+s);
        try{
        Thread.sleep(1000);
    }catch(Exception e){

    }
    System.out.print("]");
}
}
class S extends Thread{
    Display d;
    String s;
    S(Display d,String s) {
        this.d = d;
        this.s=s;
    }

    public void run(){
    d.print(s);
    }
}
class Exp{
    public static void main(String[] args) {
        Display d=new Display();
        new S(d,"hello").start();
        new S(d,"java").start();
        
    }
}