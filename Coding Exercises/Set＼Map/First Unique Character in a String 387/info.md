- [字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

> 可以假定只含有小写字母

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 `-1`

示例:

```
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
```

提示:你可以假定该字符串只包含小写字母

# 映射

# 哈希

```C++
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
```

