public class GarbageC {
    public static void main(String[] args) {
        // Creating objects
        String str1 = new String("Hello");
        String str2 = new String("World");

        // Nullifying references
        str1 = null;
        str2 = null;

        // Requesting JVM to call Garbage Collector method
        System.gc();
    }

    // finalize method is called on object once 
    // before garbage collecting it
    protected void finalize() throws Throwable {
        System.out.println("Garbage collection is performed by JVM");
    }
}
