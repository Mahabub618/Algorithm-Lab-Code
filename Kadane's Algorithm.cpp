int maxSubArray(vector<int>& a) {
    int mx = INT_MIN, cur = 0;
    for(int i=0; i<a.size(); i++)
    {
        cur += a[i];
        if(mx < cur) mx = cur;
        if(cur < 0) cur = 0;
    }
    return mx;
}
