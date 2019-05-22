package heap;

public interface IMaxHeap<E> {
    // nlogn
    boolean offer(E item);
    // nlogn
    E poll();
    E peek();
    int size();
    boolean isEmpty();
    void print();
}
