//import hashtable.separateChaining.HashNode;
//
//import java.util.HashSet;

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {

    // private static void helper(Node node, HashSet<Node> visited) {
    //     visited.add(node);
    //     for (Node neighbor : node.neighbors) {
    //         if (!visited.contains(neighbor)) {
    //             helper(neighbor, visited);
    //         }
    //     }
    // }
    public Node cloneGraph(Node node) {
        return method1(node);
    }
    
    private Node method1(Node node) {
        if (node == null) return null;
        HashMap<Node, Node> map = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();
        
        queue.offer(node);
        map.put(node, new Node(node.val));
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            map.get(cur).neighbors = new ArrayList<>();
            // add neighbors back to queue
            for (Node neighbor : cur.neighbors) {
                if (!map.containsKey(neighbor)) {
                    // now the map cotains a new node
                    map.put(neighbor, new Node(neighbor.val));
                    queue.offer(neighbor);
                }
                map.get(cur).neighbors.add(map.get(neighbor));
            }
        }
        // return the root
        return map.get(node);
    }
}
