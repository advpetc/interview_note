package heap;

import hashtable.hashcode.HashCode;
import heap.impl.MaxHeapImpl;

import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        MaxHeapImpl<Integer> maxHeap = new MaxHeapImpl<>();
        Integer[] nums = new Integer[]{2, 23, 30, 8, 32, 31, 41, 1, 15};
        for (Integer num: nums ) {
           maxHeap.offer(num);
        }
        maxHeap.print();

        PriorityQueue<Student> priorityQueue = new PriorityQueue<>((a,b) -> (a.score - b.score));
        System.out.println(priorityQueue.poll());
        System.out.println(priorityQueue.poll());
    }

    class Student {
        int score;
    }
}
