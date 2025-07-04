/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

9 |
8 |      1                        1                 ^
7 |      1------------------------1---------1       | 
6 |      1    1                   1         1       |
5 |      1    1         1         1         1       |
4 |      1    1         1    1    1         1       |  Height of walls
3 |      1    1         1    1    1    1    1       |
2 |      1    1    1    1    1    1    1    1       |
1 | 1    1    1    1    1    1    1    1    1       |
  |---------------------------------------------
0 | 1    2    3    4    5    6    7    8    9
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49. It's calculated by the distance they are apart by, which wil be the length of container and height of the small wall of both of them is the breadth of the container. 

Example 2:
Input: height = [1,1]
Output: 1
 
Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height){
    int n = height.size();
    if(n == 0 || n == 1)
        return 0;

    int area = 0;
    if(n == 2){
        return min(height[0] , height[1]);
    }

    int left = 0 , right = n - 1;

    while(left < right){
        int size = right - left;
        area = max(area , size * min(height[left] , height[right]));

        (height[left] > height[right]) ? right-- : left++;
    }

    return area;
}

int main(){
    vector<int> height = {1 , 8 , 6 , 2 , 5 , 4 , 8 , 3 , 7};
    int area = maxArea(height);
    cout << "Max area the container of the vector can hold is: " << area;    
}

//Approach of two pointer and greedy condition
/*
We initialize two pointers from both start and end.
Then we find the area between both of them which distance between them * height of smallest wall and assign max of previous area and current calculated area back to area.
Then we find which of the both pointers points to small wall as compared to other pointer, if first pointer points to small wall then increment it, else decrement second pointer.

From this approach, we find area with length also taking into consideration with perspective of the largest wall of the whole array. Even if same wall is found, we just leave it move ahead without leaving our first found largest wall.
*/