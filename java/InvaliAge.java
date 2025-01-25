import java.io.*;
class InvalidAgeException extends Exception{
    InvalidAgeException(String msg){
        super(msg);
    }
}


public class Traffic {
    static void valid(int age)throws InvalidAgeException{
        if(age<18){
            throw new InvalidAgeException("not valid");
        }else{
            System.out.println("welcome to vote");
        }
    }

public static void main(String[] args) {
    try{
        valid(15);

    }catch(Exception e){
       
        System.out.println(e);
    }
}

}