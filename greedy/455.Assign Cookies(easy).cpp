class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=-1,gs=g.size(),js=s.size();
        while(i<gs && ++j<js)     i+=(g[i]<=s[j]); //child的增加從成功這邊來
        return i;
    }
};
