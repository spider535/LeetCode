class Solution {
public:
    string complexNumberMultiply(string nums1, string nums2) {
        int a , b, c ,d;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        string temp;
        while(i < n1 && nums1[i] != '+')
            temp.push_back(nums1[i++]);
        a = stoi(temp);
        i++;
        temp = "";
        while(i < n1 && nums1[i] != 'i')
            temp.push_back(nums1[i++]);
        b = stoi(temp);
        i = 0;
        temp = "";
        while(i < n2 && nums2[i] != '+')
            temp.push_back(nums2[i++]);
        c = stoi(temp);
        i++;
        temp = "";
        while(i < n2 && nums2[i] != 'i')
            temp.push_back(nums2[i++]);
        d = stoi(temp);
        int x = a*c - b*d;
        int y = a*d + b*c;
        return to_string(x)+"+"+to_string(y)+"i";
    }
};