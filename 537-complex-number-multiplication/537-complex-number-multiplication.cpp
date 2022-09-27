class Solution {
public:
    string complexNumberMultiply(string nums1, string nums2) {
        int a , b, c ,d;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        // if(nums1[i] == '-'){
        //     a = -1;
        //     i++;
        // }
        // else
        //     a = 1;
        string temp;
        while(i < n1 && nums1[i] != '+')
            temp.push_back(nums1[i++]);
        a = stoi(temp);
        i++;
        // if(nums1[i] == '-'){
        //     b = -1;
        //     i++;
        // }
        // else
        //     b = 1;
        temp = "";
        while(i < n1 && nums1[i] != 'i')
            temp.push_back(nums1[i++]);
        b = stoi(temp);
        i = 0;
        // if(nums2[i] == '-'){
        //     c = -1;
        //     i++;
        // }
        // else
        //     c = 1;
        temp = "";
        while(i < n2 && nums2[i] != '+')
            temp.push_back(nums2[i++]);
        c = stoi(temp);
        i++;
        // if(nums2[i] == '-'){
        //     d = -1;
        //     i++;
        // }
        // else
        //     d = 1;
        temp = "";
        while(i < n2 && nums2[i] != 'i')
            temp.push_back(nums2[i++]);
        d = stoi(temp);
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        int x = a*c - b*d;
        int y = a*d + b*c;
        return to_string(x)+"+"+to_string(y)+"i";
    }
};