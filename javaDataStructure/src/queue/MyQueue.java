package queue;

public interface MyQueue<E> {
    // allocate size
    int size();

    boolean isEmpty();

    boolean offer(E e);

    E poll();
    // top element
    E peek();

    void print();
    void resize(int capacity);
}
