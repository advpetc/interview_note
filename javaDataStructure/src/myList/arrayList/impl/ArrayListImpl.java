package myList.arrayList.impl;

import myList.arrayList.IArrayList;

import java.util.Objects;

public class ArrayListImpl<E> implements IArrayList<E> {
    private E[] data;
    private int size;
    public ArrayListImpl () {
        this(10);
    }
    public ArrayListImpl(int capacity) {
        this.data = (E[]) new Objects[capacity];
        this.size = 0;
    }

    @Override
    public int capacity() {
        return data.length;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean add(E element) {
        if (size == data.length)
            throw new IllegalArgumentException("the list is full");
        data[size++] = element;
        return false;
    }

    @Override
    public void add(int index, E element) {
        if (size == data.length)
            throw new IllegalArgumentException("this list if full");
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index input incorrect");
        for (int i = size - 1; i >= index; --i) {
           data[i + 1] = data[i];
        }
        data[index] = element;
        size++;
    }

    @Override
    public boolean contains(E element) {
        for (E d : data)
            if (d == element)
                return true;
        return false;
    }

    @Override
    public E get(int index) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index input incorrect");
        return data[index];
    }

    @Override
    public void set(int index, E element) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index input incorrect");
        data[index] = element;
    }

    @Override
    public E remove(int index) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index input incorrect");
        E res = data[index];
        for (int i = index + 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size--;
        return res;
    }

    @Override
    public boolean remove(E element) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == element) {
                index = i;
            }
        }
        if (index == -1) {
            return false;
        }
        return true;
    }

    @Override
    public void print() {
        System.out.println("size: " + size);
        System.out.println("capacity: " + data.length);
        for (E d : data)
           System.out.println(d + " ");
    }

    @Override
    public void resize(int capacity) {

    }
}
