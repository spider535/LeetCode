class MedianFinder {
public:
    priority_queue<int> mxhp;
    priority_queue<int,vector<int>,greater<>> mnhp;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxhp.size() == mnhp.size()){
            if(mnhp.empty() || mnhp.top() >= num)
                mxhp.push(num);
            else{
                mxhp.push(mnhp.top());
                mnhp.pop();
                mnhp.push(num);
            }
        }
        else{
            if(mxhp.top() <= num)
                mnhp.push(num);
            else{
                mnhp.push(mxhp.top());
                mxhp.pop();
                mxhp.push(num);
            }
        }
    }
    
    double findMedian() {
        if((mxhp.size()+mnhp.size())%2 == 0)
            return (double)(mxhp.top()+mnhp.top())/(double)2;
        return mxhp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */