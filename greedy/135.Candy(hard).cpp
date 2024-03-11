class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> ans(len, 1);
        if(len < 2) return len;
        for(int i = 1; i < len; ++i) //從第二項開始，這樣就不用擔心最後面
        {
            if(ratings[i] > ratings[i-1]) ans[i] = ans[i-1]+1;
        }
        for(int j = len-2; j >= 0; --j) //從倒數第二項開始，這樣就不用擔心最前面
        {
            if(ratings[j] > ratings[j+1] && ans[j] <= ans[j+1]) ans[j] = ans[j+1]+1;
        }
        /*
        int sum = 0;
        for(int k = 0; k < len; ++k)
        {
            sum += ans[k];
        }
        return sum;
        */
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
