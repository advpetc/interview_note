// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
    public:
        int findCelebrity(int n) {
            return method4(n);
        }

        /******************************************************************************
        * Function:         int method1
        * Description:      create a vector to walk through all the people,
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method1(int n){
            vector<bool> candidate(n, true);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (candidate[i] && i != j) {
                        // has to be **everyone** knows you, but you
                        // don't know anyone
                        if (knows(i, j) || !knows(j, i)) {
                            candidate[i] = false;
                            break;
                        } else {
                            candidate[j] = false;
                        }
                    }
                }
                if (candidate[i]) {
                    return i;
                }
            }
            return -1;
        }

        /******************************************************************************
        * Function:         int method2
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method2(int n){
           for (int i = 0, j = 0; i < n; ++i) {
               for (j = 0; j < n; ++j) {
                  if (i != j && (knows(i, j) || !knows(j, i))) {
                      break;
                  }
                  if (j == n) {
                     return i; 
                  }
               }
           }
           return -1;
        }

        /******************************************************************************
        * Function:         int method3
        * Description:      
        下面这种方法是网上比较流行的一种方法，设定候选人 res
        为0，原理是先遍历一遍，对于遍历到的人i，若候选人 res 认识i，则将候选人 res
        设为i，完成一遍遍历后，我们来检测候选人 res
        是否真正是名人，我们如果判断不是名人，则返回 -1，如果并没有冲突，返回
        res，参见代码如下
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method3(int n){
            int res = 0;
            for (int i = 0; i < n; ++i) {
               if (knows(res, i)) 
                   res = i;
            }
            for (int i = 0; i < n; ++i) {
               if (res != i && (knows(res, i) || !knows(i, res))) 
                   return -1;
            }
            return res;
        }

        /******************************************************************************
        * Function:         int method4
        * Description:      
        找候选者的方法跟上面相同，但是在验证的时候，分为两段，先验证候选者前面的所有人，若候选者认识任何人，或者任何人不认识候选者，直接返回
        -1。再验证候选者后面的人，这时候只需要验证是否有人不认识候选者就可以了，因为我们在最开始找候选者的时候就已经保证了候选者不会认识后面的任何人，参见代码如下：
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method4(int n){
            int res = 0;
            for (int i = 0; i < n; ++i) {
               if (knows(res, i)) 
                   res = i;
            }
            for (int i = 0; i < res; ++i) {
               if (knows(res, i) || !knows(i, res))
                   return -1;
            }
            for (int i = res + 1; i < n; ++i) {
                if (!knows(i, res))
                    return -1;
            }
            return res;
        }
};
