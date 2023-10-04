#include<iostream>
#include <bits/stdc++.h>


using namespace std;

class MyHashMap
{
public:
    vector<int> mp;

    MyHashMap()
    {

        mp.resize(1e6 + 1, -1);
    }

    void put(int key, int value)
    {

        mp[key] = value;
    }

    int get(int key)
    {

        return mp[key];
    }

    void remove(int key)
    {

        mp[key] = -1;
    }
};


