package hashtable;

public interface IHashTable<K, V> {
    void put(K key, V value);
    V get(K key);
    V delete(K key);
    boolean isEmpty();
    int size();
    void print();
}
