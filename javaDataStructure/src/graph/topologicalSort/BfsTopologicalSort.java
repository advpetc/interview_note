package graph.topologicalSort;

import java.util.LinkedList;
import java.util.Queue;

// time complexity O(v + e)
public class BfsTopologicalSort {
    public int[] findRes(int numCourses, int[][] prequisites) {
        int[] res = new int[numCourses];
        int k = 0;
        /**
         * 入度
         */
        int[] indegree = new int[numCourses];
        for (int[] pair: prequisites) {
            indegree[pair[0]]++;
        }

        /**
         * initialization: put all node with indegree of zero into the queue
         * and res
         */
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
                res[k++] = i;
            }
        }

        while (!queue.isEmpty()) {
            int pre = queue.poll();
            for (int[] pair: prequisites) {
                // determine if the node is connected to current/pre node
                if (pair[1] == pre) {
                    indegree[pair[0]]--;
                    if (indegree[pair[0]] == 0) {
                        queue.offer(pair[0]);
                        res[k++] = pair[0];
                    }
                }
            }
        }
        return (k == numCourses) ? res : new int[0];

    }
}
