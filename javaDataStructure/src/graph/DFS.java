package graph;

import java.util.HashSet;
import java.util.List;
import java.util.Stack;

import static graph.BFS.bfs;
import static graph.BFS.bfsMatrix;

public class DFS {

    public static void dfs(List<GraphNode> list) {
        HashSet<GraphNode> visited = new HashSet<>();
        for (GraphNode node : list) {
            if (!visited.contains(node))
                helper(node, visited);
        }
    }

    private static void helper(GraphNode node, HashSet<GraphNode> visited) {
        visited.add(node);
        System.out.println(node.label);
        for (GraphNode neighbor : node.neighbors) {
            if (!visited.contains(neighbor)) {
                helper(neighbor, visited);
            }
        }
    }

    public static void dfsIterative(GraphNode node) {
        Stack<GraphNode> stack = new Stack<>();
        HashSet<GraphNode> visited = new HashSet<>();
        stack.push(node);
        visited.add(node);
        while (!stack.empty()) {
            GraphNode curr = stack.pop();
//            visited.add(curr);
            System.out.println(curr.label);
            for (GraphNode neighbor : curr.neighbors) {
                if (!visited.contains(neighbor)) {
                    stack.push(neighbor);
                    visited.add(curr);
                }
            }
        }
    }

    public static void dfsMatrixIterative(int[][] matrix) {
        Stack<Integer> stack = new Stack<>();
        int[] visited = new int[matrix.length];
        for (int i = 0; i < visited.length; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                stack.push(i);
                while (!stack.isEmpty()) {
                    Integer vertex = stack.pop();
                    System.out.println(vertex);
                    for (int j = 0; j < matrix.length; j++) {
                        if (matrix[vertex][j] == 1) {
                            if (visited[j] == 0) {
                                stack.push(j);
                                visited[j] = 1;
                            }
                        }
                    }
                }
            }

        }

    }

    public static void dfsMatrix(int[][] matrix) {
        int[] visited = new int[matrix.length];
        for (int i = 0; i < visited.length; i++) {
            if (visited[i] == 0) {
                helper(matrix, visited, i);
            }
        }
    }

    public static void helper(int[][] matrix, int[] visited, int vertex) {
        visited[vertex] = 1;
        System.out.println(vertex);
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[vertex][i] == 1) {
                if (visited[i] == 0) {
                    helper(matrix, visited, i);
                }
            }
        }
    }

    public static void dfs2(GraphNode node) {
        helper(node, new HashSet<>());
    }

    public static void main(String[] args) {
        GraphNode a = new GraphNode(0);
        GraphNode b = new GraphNode(1);
        GraphNode c = new GraphNode(2);
        GraphNode d = new GraphNode(3);
        GraphNode e = new GraphNode(4);
        GraphNode f = new GraphNode(5);

        a.neighbors.add(b);
        a.neighbors.add(d);
        a.neighbors.add(f);

        b.neighbors.add(a);
        b.neighbors.add(e);
        b.neighbors.add(c);

        c.neighbors.add(b);
        c.neighbors.add(e);

        d.neighbors.add(a);
        d.neighbors.add(e);

        e.neighbors.add(d);
        e.neighbors.add(b);
        e.neighbors.add(c);

        f.neighbors.add(a);

        int[][] matrix = new int[][]{
                {0, 1, 0, 1, 0, 1},
                {1, 0, 1, 0, 1, 0},
                {0, 1, 0, 0, 1, 0},
                {1, 0, 0, 0, 1, 0},
                {0, 1, 1, 1, 0, 0},
                {1, 0, 0, 0, 0, 0}
        };
//        dfs2(a);
//        dfsMatrix(matrix);
//        dfsIterative(a);
//        dfsMatrixIterative(matrix);
//        bfs(a);
        bfsMatrix(matrix);
    }

}
