package stack.impl;

import stack.IArrayStack;

public class ArrayStackImpl<E> implements IArrayStack<E> {
    private E[] data;
    private int elementCount;

    public ArrayStackImpl(int capacity) {
        this.data = (E[]) new Object[capacity];
        this.elementCount = 0;
    }

    public ArrayStackImpl() {
        this.data = (E[]) new Object[10];
        this.elementCount = 0;
    }

    @Override
    public int capacity() {
        return 0;
    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public void push(E e) {
        if (elementCount == data.length)
            resize(data.length * 2);
        data[elementCount++] = e;
    }

    @Override
    public E pop() {
        if (isEmpty()) return null;
        E obj = peek();
        elementCount--;
        data[elementCount] = null;
        return obj;
    }

    @Override
    public E peek() {
        if (isEmpty()) return null;
        return data[elementCount - 1];
    }

    @Override
    public void print() {
        System.out.println("size : " + elementCount);
        System.out.println("capacity : " + data.length);
        for (int i = 0; i < elementCount; ++i) {
            System.out.print(data[i] + " |");
        }
        System.out.println();
    }

    @Override
    public void resize(int capacity) {
        E[] temp = (E[]) new Object[capacity];
        for (int i = 0; i < elementCount; i++) {
            temp[i] = data[i];
        }
        data = temp;
    }
}
