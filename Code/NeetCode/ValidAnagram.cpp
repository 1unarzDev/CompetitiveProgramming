#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> characters;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++){
            if(characters.find(s[i]) == characters.end()) characters[s[i]] = 1;
            else characters[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            if(characters.find(t[i]) == characters.end()) return false;
            else characters[t[i]]--;
            if(characters[t[i]] < 0) return false;
        }
        return true;
    }
};