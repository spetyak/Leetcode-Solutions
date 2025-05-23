import java.util.HashMap;

/**
 * @author spetyak
 * 
 * Runtime: Beats 62.93% of Java submissions
 * Memory: Beats 39.73% of Java submissions
 */
public class lc146 {

    /**
     * A node data structure for a doubly linked list used to track cache access recency.
     */
    public static class Node<T> {

        public T key;           // the key for a given cache entry
        public T value;         // the value for a given cache entry
        public Node<T> next;    // a pointer to the next node in the recency list
        public Node<T> prev;    // a pointer to the previous node in the recency list

        /**
         * Constructor for the Node class.
         * 
         * @param key the given entry's key
         * @param val the given value's value
         */
        public Node(T key, T val) {

            this.key = key;
            this.value = val;
            this.next = null;
            this.prev = null;

        }

    }

    /**
     * A doubly linked list data structure used to track cache access recency.
     */
    public static class DLL<T> {

        public Node<T> head;    // the first element of the linked list
        public Node<T> tail;    // the last element of the linked list

        /**
         * Constructor for the doubly linked list class.
         */
        public DLL() {
            this.head = null;
            this.tail = null;
        }

        /**
         * Adds the given node to the front of the linked list.
         * 
         * @param newNode the node to be added to the list
         */
        public void addFirst(Node<T> newNode) {
            if (this.head == null)
            {
                this.head = newNode;
                this.tail = newNode;
                return;
            }
            this.head.prev = newNode;
            newNode.next = this.head;
            this.head = newNode;
        }

        /**
         * Adds the given node to the end of the linked list.
         * 
         * @param newNode the node to be added to the list
         */
        public void addLast(Node<T> newNode) {
            if (this.head == null)
            {
                this.head = newNode;
                this.tail = newNode;
                return;
            }
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }

        /**
         * Removes the given node from the linked list.
         * 
         * @param node the node to be removed from the list
         */
        public void remove(Node<T> node) {

            if (node.prev != null && node.next != null)
            {
                node.prev.next = node.next;
                node.next.prev = node.prev;
                node.next = null;
                node.prev = null;
            }
            else if (node.prev == null && node.next == null)
            {
                this.head = null;
                this.tail = null;
            }
            else if (node.prev == null)
            {
                this.head = node.next;
                node.next.prev = null;
                node.next = null;
            }
            else if (node.next == null)
            {
                this.tail = node.prev;
                node.prev.next = null;
                node.prev = null;
            }
            
        }

        /**
         * Removes and returns the first node from the linked list.
         * 
         * @return The head of the linked list.
         */
        public Node<T> removeFirst() {
            if (this.head == null)
            {
                return null;
            }
            Node<T> removedObj = this.head;
            this.head = this.head.next;
            return removedObj;
        }

        /**
         * Removes and returns the last node from the linked list.
         * 
         * @return The tail of the linked list.
         */
        public Node<T> removeLast() {

            Node<T> removedObj = null;

            if (this.head == this.tail)
            {
                removedObj = this.head;
                this.head = null;
                this.tail = null;
            }
            else if (this.tail != null)
            {
                removedObj = this.tail;
                this.tail = this.tail.prev;
                this.tail.next = null;
            }

            
            return removedObj;
        }

    }

    /**
     * A data structure that follows the constraints of a Least Recently Used (LRU) Cache.
     */
    public static class LRUCache {

        public HashMap<Integer, Node<Integer>> cache;   // a map representing a cache structure
        public DLL<Integer> usedList;                   // a list to track key use recency
        public int initialCapacity;                     // the capacity of the cache structure

        /**
         * Constructor for the LRUCache class.
         * 
         * @param capacity the capacity of the cache
         */
        public LRUCache(int capacity) {

            cache = new HashMap<>(capacity);
            usedList = new DLL<>();
            initialCapacity = capacity;
            
        }
        
        /**
         * Returns the value associated with {@code key} if the key exists in the cache, 
         * {@code} -1 if not.
         * 
         * @param key the key to check the cache for
         * 
         * @return The value associated with the given key if the key exists in the cache, -1 if not.
         */
        public int get(int key) {

            if (cache.containsKey(key)) // if the given key already exists in the cache
            {

                Node<Integer> readNode = cache.get(key);

                // move the node to the front of the recency list
                usedList.remove(readNode);
                usedList.addFirst(readNode);

                return readNode.value;

            }
            else
            {
                return -1;
            }
            
        }
        
        /**
         * Adds the key-value pair to the LRU cache.
         * If the key already exists in the cache, it's value is updated.
         * If the number of keys exceeds the cache capacity, the least recently used key is evicted.
         * 
         * @param key the key portion of the given cache entry key-value pair
         * @param value the value portion of the given cache entry key-value pair
         */
        public void put(int key, int value) {

            if (cache.containsKey(key)) // if the given key already exists in the cache
            {
                Node<Integer> updateNode = cache.get(key);  // get the current entry from the cache
                usedList.remove(updateNode);                // remove from the recency list
                updateNode.value = value;                   // update the value
                usedList.addFirst(updateNode);              // add to front of recency list
                cache.put(key, updateNode);                 // update cache
                return;
            }

            if (cache.size() == initialCapacity) // if the cache is already full
            {

                /*
                 * Evict the least recently used entry from the cache.
                 */
                Node<Integer> leastRecentlyUsed = usedList.removeLast();
                cache.remove(leastRecentlyUsed.key);
                
            }

            /*
             * Add the new key-value pair to the cache.
             */
            Node<Integer> newNode = new Node<>(key, value);
            cache.put(key, newNode);
            usedList.addFirst(newNode);
            
        }

    }

    public static void main(String[] args) {

        

    }

}