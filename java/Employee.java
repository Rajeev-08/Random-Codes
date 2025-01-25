import java.util.Scanner;
class Emp{
String name;
int age;
int ph;
int salary;
String address;

public Emp(String name,int age,int ph,int salary,String address){
    this.name=name;
    this.age=age;
    this.ph=ph;
    this.salary=salary;
    this.address=address;
}
public void printSalary(){
    System.out.println("salary :"+salary);
}
public void print(){
    System.out.println("Name :"+name+"\nAge :"+age+"\nph :"+ph+"\naddress :"+address);
}
}

class Officer extends Emp {
    String specialization;
    public Officer(String name,int age,int ph,int salary,String address,String specialization){
        super(name,age,ph,salary,address);
        this.specialization=specialization;  
    }
}
class Manager extends Emp{
    String dept;
    public Manager(String name,int age,int ph,int salary,String address,String dept){
        super(name,age,ph,salary,address);
        this.dept=dept;
    }
}
class Employee{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);

        System.out.println("Officer Details");
        System.out.print("enter name :");
        String name=s.nextLine();
        System.out.print("enter age ;");
        int age=s.nextInt();
        System.out.print("enter ph ;");
        int ph=s.nextInt();
        System.out.print("enter salary ;");
        int salary=s.nextInt();
        System.out.print("enter address :");
        s.nextLine();
        String address=s.nextLine();
        System.out.print("enter secialization :");
        String specialization=s.nextLine();
        Officer o=new Officer(name, age, ph, salary, address, specialization);
       
        System.out.println("Manager Details");
        System.out.print("enter name :");
         name=s.nextLine();
        System.out.print("enter age ;");
        age=s.nextInt();
        System.out.print("enter ph ;");
         ph=s.nextInt();
        System.out.print("enter salary ;");
         salary=s.nextInt();
        System.out.print("enter address :");
        s.nextLine();
         address=s.nextLine();
        System.out.print("enter dept :");
        String dept=s.nextLine();
        Manager m=new Manager(name, age, ph, salary, address, dept);

        System.out.println("Officer");
        o.print();
        o.printSalary();
        System.out.println("secialization :"+specialization);

        System.out.println("Manager");
        m.print();
        m.printSalary();
        System.out.println("dept ;"+dept);   
    }
}