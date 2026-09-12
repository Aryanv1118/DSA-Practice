class Solution{
public:
    vector<int> ans;
    vector<vector<long long>> memo;
    vector<vector<vector<int>>> best;
    int getNext(int i,vector<vector<int>>& intervals){
        int lo=i+1,hi=intervals.size();
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(intervals[mid][0]>intervals[i][1]) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
    long long dfs(int i,int k,vector<vector<int>>& intervals){
        if(i==intervals.size()||k==4) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
        int next=getNext(i,intervals);
        long long skip=dfs(i+1,k,intervals);
        long long take=intervals[i][2]+dfs(next,k+1,intervals);
        vector<int> tv={intervals[i][3]};
        if(k<3&&next<intervals.size())
            tv.insert(tv.end(),best[next][k+1].begin(),best[next][k+1].end());
        sort(tv.begin(),tv.end());
        vector<int> sv;
        if(i+1<intervals.size()) sv=best[i+1][k];
        if(take>skip){
            best[i][k]=tv;
            return memo[i][k]=take;
        }
        if(skip>take){
            best[i][k]=sv;
            return memo[i][k]=skip;
        }
        best[i][k]=min(tv,sv);
        return memo[i][k]=take;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals){
        int n=intervals.size();
        memo.assign(n,vector<long long>(4,-1));
        best.assign(n,vector<vector<int>>(4));
        for(int i=0;i<n;i++) intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end());
        dfs(0,0,intervals);
        return best[0][0];
    }
};