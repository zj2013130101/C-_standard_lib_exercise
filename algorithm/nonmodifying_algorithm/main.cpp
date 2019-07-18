
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstring>


using namespace std;




class Solution {
public:
    void replaceSpace(char *str,int length) {
        string tmp(str);
        string another;
        another.reserve(2*length);
        transform(tmp.begin(), tmp.end(), another.begin(), [&](char elem){
            if(elem == ' ')
            {
                another.insert(another.size(), "%20");
            }else{
                return elem;
            }
        });
        cout << another << endl;

    }
};


class Solution2 {
public:
    void replaceSpace(char *str, int length) {
        if(str== nullptr || *str == '\0')
            return;
        int oldStrLen=0, SpaceNum=0, newStrLen=0;
        char *tmp = new char[length];
        char* tmpStr = str;

        for(; *tmpStr != '\0'; tmpStr++)
        {
            oldStrLen++;
            if(*tmpStr == ' ')
                SpaceNum++;
        }

        newStrLen = oldStrLen + SpaceNum*2;
        str[newStrLen] = '\0';
        if( newStrLen > length)
            return;
        for(int i=0, j=0; i < oldStrLen; i++, j++)
        {
            if(*(str+i) == ' ')
            {
                *(tmp+j) = '%';
                *(tmp+j+1) = '2';
                *(tmp+j+2) = '0';
                j+=2;
            } else
                *(tmp+j) = *(str+i);
        }
        for(int i=0; i < newStrLen; i++)
        {
            *(str + i) = *(tmp + i);
        }
        delete[] tmp;
    }
};




int main()
{
    char a[100] = "hello world";
    Solution2().replaceSpace(a, 100);

    cout << a << endl;

    return 0;
}




















