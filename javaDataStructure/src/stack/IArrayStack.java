package stack;

public interface IArrayStack<E> {
    // container size
    int capacity();
    // allocate size
    int size();

    boolean isEmpty();

    void push(E e);

    E pop();
    // top element
    E peek();

    void print();
    void resize(int capacity);
}
