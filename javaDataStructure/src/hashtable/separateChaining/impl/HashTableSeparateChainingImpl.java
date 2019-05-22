package hashtable.separateChaining.impl;

import hashtable.IHashTable;
import hashtable.separateChaining.HashNode;

public class HashTableSeparateChainingImpl<K, V> implements IHashTable<K, V> {
    private HashNode[] hashNodes;
    private int capacity;
    private int size;

    public HashTableSeparateChainingImpl() {
        this.capacity = 10;
        hashNodes = new HashNode[capacity];
    }

    public HashTableSeparateChainingImpl(int capacity) {
        this.capacity = capacity;
        hashNodes = new HashNode[capacity];
    }

    private int hash(K key) {
        return key.hashCode() % capacity;
    }

    @Override
    public void put(K key, V value) {
        HashNode<K, V> hashNode = new HashNode<>(key, value);
        int index = hash(key);
        HashNode currHashNode = hashNodes[index];
        HashNode preHashNode = null;
        if (currHashNode == null) {
           hashNodes[index] = hashNode;
        } else {
            // get the last node from the linkedlist
            // if found the key already, simply replace the
            // value of the node
            while (currHashNode != null) {
                if (currHashNode.key.equals(key)) {
                    currHashNode.value = value;
                    return;
                }
                preHashNode = currHashNode;
                currHashNode = currHashNode.next;
            }
            preHashNode.next = hashNode;
        }
        size++;
    }

    @Override
    public V get(K key) {
        int index = hash(key);
        HashNode currHashNode = hashNodes[index];

        while (currHashNode != null) {
            if (currHashNode.key.equals(key)) {
                return (V) currHashNode.value;
            }
            currHashNode = currHashNode.next;
        }
        return null;
    }

    @Override
    public V delete(K key) {
        int index = hash(key);
        HashNode currHashNode = hashNodes[index];
        HashNode preHashNode = null;

        while (currHashNode != null) {
            if (currHashNode.key.equals(key)) {
                break;
            }
            preHashNode = currHashNode;
            currHashNode = currHashNode.next;
        }

        if (currHashNode == null) return null;
        else if (preHashNode == null) {
            hashNodes[index] = currHashNode.next;
        } else {
            preHashNode.next = currHashNode.next;
        }
        size--;
        return null;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void print() {
        for (HashNode<K, V> hashNode : hashNodes) {
            if (hashNode != null) {
                while (hashNode != null) {
                    System.out.print("key: " + hashNode.key + " value: " + hashNode.value + " -> ");
                    hashNode = hashNode.next;
                }
                System.out.println(" null");
            }
        }
        System.out.println("size: " + size);
    }
}
