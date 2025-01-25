//Write a Java program that shows thread priorities
class MyThread extends Thread {
    public void run() {
        System.out.println("Running thread name: " + Thread.currentThread().getName());
        System.out.println("Running thread priority: " + Thread.currentThread().getPriority());
    }
}

public class Main {
    public static void main(String[] args) {
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();
        thread1.setName("Thread1");
        thread2.setName("Thread2");

        // Setting priorities
        thread1.setPriority(Thread.MIN_PRIORITY); // 1
        thread2.setPriority(Thread.MAX_PRIORITY); // 10

        // Starting threads
        thread1.start();
        thread2.start();
    }
}

