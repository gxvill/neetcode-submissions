class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>, greater<int>> right;

    MedianFinder(){

    }

    void addNum(int num) {
        if(left.size() == 0){
            left.push(num);
            return;
        }

        if(num > left.top()){
            right.push(num);
        }
        else{
            left.push(num);
        }

        while(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }

        while(right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }
        else if(left.size() < right.size()){
            return right.top();
        }
        else{
            return (left.top() + right.top()) / 2.0;
        }
    }
};
