package myList.linkedList.impl;

import myList.linkedList.ILinkedList;

public class LinkedListImpl<E> implements ILinkedList<E> {
    private int size;
    private ListNode dummy;

    public LinkedListImpl() {
        this.dummy = new ListNode(0);
        this.size = 0;
    }

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void addIndex(E data, int index) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index is out of bound");
        ListNode prev = dummy;
        for (int i = 0; i < index; ++i)
            prev = prev.next;
        ListNode node = new ListNode(data);
        node.next = prev.next;
        prev.next = node;
        size++;
    }

    @Override
    public boolean addElement(E data) {
        addIndex(data, size);
        return true;
    }

    @Override
    public void addFirst(E data) {
        addIndex(data, 0);
    }

    @Override
    public void addLast(E data) {
        addIndex(data, size);
    }

    @Override
    public E removeFirst() {
        return removeIndex(0);
    }

    @Override
    public boolean removeElement(E data) {
        ListNode prev = dummy;
        while (prev.next != null) {
            if (prev.next.data == data)
                break;
            prev = prev.next;
        }
        if (prev.next != null) {
            ListNode delNode = prev.next;
            prev.next = delNode.next;
            delNode.next = null;
            size--;
            return true;
        }
        return false;
    }

    @Override
    public E removeLast(E data) {
        return removeIndex(size - 1);
    }

    @Override
    public E removeIndex(int index) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index is out of bound");
        ListNode prev = dummy;
        for (int i = 0; i < index; ++i)
            prev = prev.next;
        ListNode delNode = prev.next;
        prev.next = delNode.next;
        delNode.next = null;
        size--;
        return (E) delNode.data;
    }

    @Override
    public E get(int index) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index is out of bound");
        ListNode curr = dummy.next;
        for (int i = 0; i < index; ++i)
            curr = curr.next;
        return (E) curr.data;
    }


    @Override
    public void set(int index, E data) {
        if (index < 0 || index > size)
            throw new IllegalArgumentException("index is out of bound");
        ListNode curr = dummy.next;
        for (int i = 0; i < index; ++i)
            curr = curr.next;
        curr.data = data;
    }

    @Override
    public E getFirst() {
        return get(0);
    }

    @Override
    public E getLast() {
        return get(size - 1);
    }

    @Override
    public boolean contains(E data) {
        ListNode curr = dummy;
        while (curr != null) {
            if (curr.data == data)
                return true;
            curr = curr.next;
        }
        return false;
    }

    private class ListNode<E> {
        public E data;
        public ListNode next;

        public ListNode(E data) {
            this.data = data;
            this.next = null;
        }
    }
}
