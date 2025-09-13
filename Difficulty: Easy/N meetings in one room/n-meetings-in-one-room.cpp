class Solution {
  public:
      struct Data{
        int start , end;
    };
    static bool comp(const Data &a, const Data &b) {
    return a.end < b.end;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        const int N = start.size();
        vector<Data> arr(N);
        for(int i = 0; i < start.size(); i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        sort(arr.begin(), arr.end(), comp);
        int cnt = 1;
        int freeTime = arr[0].end;
        for(int i = 1; i < start.size(); i++){
            if(arr[i].start > freeTime){
               cnt++;
                freeTime = arr[i].end;
            }
        }
        return cnt;
        
    }
};

