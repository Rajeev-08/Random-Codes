//Q4

abstract class Marks{
   public abstract float getPercentage();
}
class A extends Marks{
    float m1,m2,m3;
    public A(int mark1,int mark2,int mark3){
        m1=mark1;
        m2=mark2;
        m3=mark3;
    }
    public float getPercentage(){
       float p=((m1+m2+m3)/300)*100;

return p;
    }
}
class B extends Marks{
    float m1,m2,m3,m4;
    public B(int mark1,int mark2,int mark3,int mark4){
        m1=mark1;
        m2=mark2;
        m3=mark3;
        m4=mark4;
    }
    public float getPercentage(){
       float p=((m1+m2+m3+m4)/400)*100;

return p;
    }
}
class Student{
    public static void main(String[]args){
                A a=new A(78,89,98);
        B b=new B(45,66,88,100);
        float ar=+a.getPercentage();
            System.out.println("percentage of marks obtained by student A : "+ar+" %");
            System.out.println("percentage of marks obtained by student B : "+b.getPercentage()+" %");
    }
}