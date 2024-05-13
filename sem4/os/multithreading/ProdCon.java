import java.util.concurrent.Semaphore;

public class ProdCon {
    private static final int BUFFER_SIZE = 5;
    private static Semaphore mutex = new Semaphore(1);
    private static Semaphore empty = new Semaphore(BUFFER_SIZE);
    private static Semaphore full = new Semaphore(0);

    private static int[] buffer = new int[BUFFER_SIZE];
    private static int in = 0;
    private static int out = 0;

    static class Producer extends Thread {
        public void run() {
            while (true) {
                try {
                    empty.acquire(); // Wait if the buffer is full
                    mutex.acquire(); // Obtain exclusive access to the buffer
                    System.out.println("empty: "+empty);
                    System.out.println("mutex: "+mutex);
                    buffer[in] = 1; // Produce an item
                    in = (in + 1) % BUFFER_SIZE;
                    System.out.println("Producer produced. Items in buffer: " + availableItems());
                    mutex.release(); // Release the buffer
                    full.release(); // Signal that buffer is not empty
                    System.out.println("full: "+full);
                    System.out.println("mutex: "+mutex);
                    Thread.sleep(1000); // Simulate some time for production
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumer extends Thread {
        public void run() {
            while (true) {
                try {
                    full.acquire(); // Wait if the buffer is empty
                    mutex.acquire(); // Obtain exclusive access to the buffer
                    System.out.println("full: "+full);
                    System.out.println("mutex: "+mutex);
                    buffer[out] = 0; // Consume an item
                    out = (out + 1) % BUFFER_SIZE;
                    System.out.println("Consumer consumed. Items in buffer: " + availableItems());
                    mutex.release(); // Release the buffer
                    empty.release(); // Signal that buffer is not full
                    System.out.println("empty: "+empty);
                    System.out.println("mutex: "+mutex);
                    Thread.sleep(1500); // Simulate some time for consumption
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private static int availableItems() {
        return (in - out + BUFFER_SIZE) % BUFFER_SIZE;
    }

    public static void main(String[] args) {
        Producer producer = new Producer();
        Consumer consumer = new Consumer();
        producer.start();
        consumer.start();
    }
}
