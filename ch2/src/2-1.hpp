//
// Created by ice_city on 11/04/2017.
//

#ifndef DATESTRUCT_2_1_HPP
#define DATESTRUCT_2_1_HPP

#include <vector>

struct Node {
    int      val;
    Node*   next;
    Node(int val, Node* next ) : val(val), next(next) { }
};

std::vector<int> Josephus(int n, int s, int m) {
    Node* root = new Node(1, nullptr);
    root->next = root;
    Node* t    = root;
    Node* begin = s == 1 ? t : nullptr;
    std::vector<int> result;
    for (int i = 2; i <= n; ++i) {
        t->next = new Node(i,root);
        t = t->next;
        if (i == s) {
           begin = t;
        }
    }
    while (n--) {
        for (int i = 1; i < m-1; ++i) {
            begin = begin->next;
        }
        result.push_back(begin->next->val);
        t = begin->next;
        begin->next = t->next;
        begin = t->next;
        delete(t);
    }
    return result;
}
#endif //DATESTRUCT_2_1_HPP
