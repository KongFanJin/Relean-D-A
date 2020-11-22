class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> ans(26, 0); // 创建一个长度为26的vector

        for (int i = 0; i < s.length(); i++) {
            // 对于字符`a`与`b`的ASCII相差1
            // s[i] - 'a'位置对应元素的值+1,即记录字符的重复度
            ans[s[i] - 'a'] += 1; 
        }

        for (int j = 0; j < s.length(); j++) {
            // 取出字符重复度为1的位置信息
            if (ans[s[j] - 'a'] == 1) {
                return j;
            }
        }

        return -1;
    }
};