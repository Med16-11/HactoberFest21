//Question : 
//Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

//Input:
//N = 5, K = 3
//KSortedArray[][] = {{1 3 5 7 9},{0 2 4 6 8},{2 3 5 7 11}}
//Output: 1 2
//Explanation: K = 3
//A:[1 3 5 7 9]
//B:[0 2 4 6 8]
//C:[2 3 5 7 11]
//Smallest range is formed by number 1present in first list and 2 is present in both 2nd and 3rd list.

//Solution

pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          //code here
        pair<int, int> answer{0, INT_MAX};
        map<pair<int, int>, int> map;
        for(int i = 0; i < k; i ++) {
           map[{a[i][0], i}] = 0;
        }
        
        
        while(1) {
           int min_val = map.begin() -> first.first;
           int max_val = map.rbegin() -> first.first;
           if(answer.second - answer.first > max_val - min_val) {
               answer = {min_val, max_val};
           }
           int row = map.begin() -> first.second;
           int col = map.begin() -> second;
           if(col + 1 == n) break;
           map.erase(map.begin() -> first);
           map[{a[row][col + 1], row}] = col + 1;
       }
       
       return answer;
    }
