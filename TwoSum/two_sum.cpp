#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        //边角问题，我们要考虑边角问题的处理
        vector<int> ret;
        if(numbers.size() <= 1)
            return ret;
        //新建一个map<key,value> 模式的来存储numbers里面的元素和index，
        //这里的unordered_map相当于hash_map
        unordered_map<int,int> myMap;
        for(int i = 0; i < numbers.size(); ++i)
            myMap[numbers[i]] = i;
        for(int i = 0; i < numbers.size(); ++i)
        {
            int rest_val = target - numbers[i];
            if(myMap.find(rest_val)!=myMap.end())
            {
                int index = myMap[rest_val];
                if(index == i)
                    continue;     //如果是同一个数字，我们就pass，是不会取这个值的
                if(index < i)
                {
                    ret.push_back(index+1);  //这里+1是因为题目说明白了要non-zero based index
                    ret.push_back(i+1);
                    return ret;
                }
                else
                {
                    ret.push_back(i+1);
                    ret.push_back(index+1);
                    return ret;
                }
            }
        }
    }
};

int main()
{

	return 0;
}