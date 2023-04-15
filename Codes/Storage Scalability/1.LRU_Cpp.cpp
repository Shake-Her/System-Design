#include <bits/stdc++.h>

class LRUCache
{
public:
    // created a Doubly linked list!
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;

        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int size;
    unordered_map<int, node *> mp;

    LRUCache(int capacity)
    {
        // initital configration!
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // My_functions!
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node *delNode)
    {
        node *delprev = delNode->prev;
        node *delNext = delNode->next;
        delprev->next = delNext;
        delNext->prev = delprev;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {

            node *temp = mp[key];
            int res = temp->val;
            mp.erase(key);

            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *exist = mp[key];
            mp.erase(key);
            deleteNode(exist);
        }
        if (mp.size() == size)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mp[key] = head->next;
    }
};
