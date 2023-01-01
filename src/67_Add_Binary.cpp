class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size(), lenb = b.size();
        while(lena < lenb){
            a = '0' + a;
            lena++;
        }
        while(lena > lenb){
            b = '0' + b;
            lenb++;
        }
        for(int i = lena - 1; i > 0; i--){
            a[i] = a[i] - '0' + b[i];
            if(a[i] >= '2'){
                a[i] = (a[i] - '0') % 2 + '0';
                a[i-1] = a[i-1] + 1;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if(a[0] >= '2'){
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};