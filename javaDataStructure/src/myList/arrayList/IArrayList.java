package myList.arrayList;

public interface IArrayList<E> {
    // container size
    int capacity();
    // allocate size
    int size();

    boolean isEmpty();
    boolean add(E element);
    void add(int index, E element);
    boolean contains(E element);
    E get(int index);
    void set(int index, E element);
    E remove(int index);
    boolean remove(E element);

    void print();
    void resize(int capacity);
}
