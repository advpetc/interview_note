package myList.linkedList;

public interface ILinkedList<E> {
    int size();
    boolean isEmpty();
    void addIndex(E data, int index);
    boolean addElement(E data);
    void addFirst(E data);
    void addLast(E data);
    E removeFirst();
    E removeLast(E data);
    E removeIndex(int index);
    boolean removeElement(E data);
    E get(int index);
    void set(int index, E data);
    E getFirst();
    E getLast();
    boolean contains(E data);
}
