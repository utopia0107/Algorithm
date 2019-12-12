#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> phonketmonType;
    for(int i=0;i<nums.size();i++)
    {
        phonketmonType.insert(nums[i]);
    }
    answer=nums.size()/2>phonketmonType.size()?phonketmonType.size():nums.size()/2;
    return answer;
}
