class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aam = stoi(arriveAlice.substr(0,2));
        int aad = stoi(arriveAlice.substr(3));
        int aa = 0;
        for(int i = 0 ; i < aam-1 ; i++){
            aa += month[i];
        }
        aa += aad;
        int alm = stoi(leaveAlice.substr(0,2));
        int ald = stoi(leaveAlice.substr(3));
        int al = 0;
        for(int i = 0 ; i < alm-1 ; i++){
            al += month[i];
        }
        al += ald;
        int bam = stoi(arriveBob.substr(0,2));
        int bad = stoi(arriveBob.substr(3));
        int ba = 0;
        for(int i = 0 ; i < bam-1 ; i++){
            ba += month[i];
        }
        ba += bad;
        int blm = stoi(leaveBob.substr(0,2));
        int bld = stoi(leaveBob.substr(3));
        int bl = 0;
        for(int i = 0 ; i < blm-1 ; i++){
            bl += month[i];
        }
        bl += bld;
        vector<pair<int,int>> temp = {{aa,0},{al,1},{ba,0},{bl,1}};
        sort(temp.begin(),temp.end());
        bool flag = false , f = false;
        int x;
        for(auto &it : temp){
            if(it.second == 0 && !flag)
                flag = true;
            else if(it.second == 0 && flag){
                x = it.first;
                f = true;
            }
            else if(it.second == 1 && f)
                return it.first-x+1;
            else
                return 0;
        }
        return 0;
    }
};