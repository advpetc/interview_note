package stack;

public interface ILinkedListStack<E> {
    // allocate size
    int size();

    boolean isEmpty();

    void push(E e);

    E pop() throws Exception;
    // top element
    E peek() throws Exception;

    void print();
}
