#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int maxx, minn;

    while (s != "6174") {
        stringstream s1, s2, s3;

        // sort对string类型数据进行字符串内排序,升序, s变为最大值
        sort(s.begin(), s.end());
        s1 << s;
        s1 >> minn;

        // reverse将string反转, s变为最小值
        reverse(s.begin(), s.end());
        s2 << s;
        s2 >> maxx;

        int num = maxx - minn;

        cout << maxx << " - " << minn << " = " << num << "\n";

        s3 << num;
        s3 >> s;

        for (int i = s.size(); i < 4; i++)
            s += '0';
    }

    return 0;
}