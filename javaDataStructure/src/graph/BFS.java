package graph;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    public static void bfs(GraphNode graphNode) {
        HashSet<GraphNode> visited = new HashSet<>();
        Queue<GraphNode> queue = new LinkedList<>();
        visited.add(graphNode);
        queue.offer(graphNode);
        while (!queue.isEmpty()) {
//            int size = queue.size();
            // level order
//            for (int i = 0; i < size; ++i) {
                GraphNode node = queue.poll();
                System.out.println(node.label);
                for (GraphNode neighbor : node.neighbors) {
                    if (!visited.contains(neighbor)) {
                        queue.offer(neighbor);
                        visited.add(neighbor);
                    }
                }
//            }
        }
    }

    public static void bfsMatrix(int[][] matrix) {
        int[] visited = new int[matrix.length];
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < visited.length; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                queue.offer(i);
                while (!queue.isEmpty()) {
                    Integer vertex = queue.poll();
                    System.out.println(vertex);
                    for (int j = 0; j < matrix.length; j++) {
                        if (matrix[vertex][j] == 1) {
                            if (visited[j] == 0) {
                                queue.offer(j);
                                visited[j] = 1;
                            }
                        }
                        
                    }
                }
            }
            
        }
    }
}
