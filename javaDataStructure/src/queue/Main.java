package queue;

import queue.impl.ArrayCirclarOfQueueImpl;
import queue.impl.ArrayOfQueueImpl;
import queue.impl.LinkedListOfQueue;

public class Main {
    public static void testLinkedListOfQueue() {
        MyQueue<Integer> queue = new LinkedListOfQueue<>();
        for (int i = 0; i < 8; ++i) {
            queue.offer(i);
            queue.print();
        }
        queue.poll();
        queue.print();
        System.out.println(queue.peek());
    }
    public static void main(String[] args) {
//        testLinkedListOfQueue();
//        testArrayOfQueue();
        testCircularQueue();
    }

    public static void testArrayOfQueue() {
        MyQueue<Integer> queue = new ArrayOfQueueImpl<>();
        for (int i = 0; i < 11; ++i) {
            queue.offer(i);
            queue.print();
        }
        System.out.println(queue.poll());
        queue.print();
        System.out.println(queue.peek());
    }

    public static void testCircularQueue() {
        MyQueue<Integer> queue = new ArrayCirclarOfQueueImpl<>();
        for (int i = 0; i < 9; ++i) {
            queue.offer(i);
        }
        queue.print();
        queue.poll();
        queue.poll();
        queue.poll();
        queue.print();
        queue.offer(11);
        queue.offer(21);
        queue.offer(31);
        queue.print();
        queue.offer(41);
    }
}
