class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>lq;
    priority_queue<int,vector<int>,greater<int>>rq;
    void addNum(int num) {
        lq.push(num);
        rq.push(lq.top());
        lq.pop();
        if(rq.size()>lq.size()){
            lq.push(rq.top());
            rq.pop();
        }
    }
    
    double findMedian() {
        return lq.size() > rq.size() ? lq.top() : (lq.top()+rq.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */