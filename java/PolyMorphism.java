abstract class Shape{
    abstract void sides();
}
class Rect extends Shape{
    void sides(){
        System.out.println("number of sides of rect : 4");
    }
}
class Triangle extends Shape{
    void sides(){
        System.out.println("number of sides of triangle : 3");
    }
}
class Hexagon extends Shape{
    void sides(){
        System.out.println("no of sides of hexagon : 6");
    }
}
class Exp{
    public static void main(String[] args) {
        new Rect().sides();
        new Triangle().sides();
        new Hexagon().sides();

    }
}