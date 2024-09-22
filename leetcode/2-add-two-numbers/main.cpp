#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto newRoot = new ListNode();
        auto it = newRoot;
        while(true) {
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;
            int sum = digit1+digit2+carry;
            carry = sum / 10;
            it->val = sum % 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            if (!l1 && !l2 && carry == 0) {
                break;
            }
            it->next = new ListNode();
            it = it->next;
        }
        return newRoot;
    }
};

ListNode* generateListNode(std::vector<int> numbers) {
    auto rootNode = new ListNode();
    auto tempNode = rootNode;
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        tempNode->val = *it;
        if (it + 1 != numbers.end()) {
            tempNode->next = new ListNode();
            tempNode = tempNode->next;
        }
    }
    for (const auto& number : numbers) {
    }

    return rootNode;
}

void printNode(ListNode* node) {
    auto it = node;
    std::cout << "[";
    while(true) {
        std::cout << it->val;
        if (!it->next) {
            break;
        }
        std::cout << ",";
        it = it->next;
    }
    std::cout << "]\n";
}

bool isNodeEquals(ListNode* n1, ListNode* n2) {
    printNode(n1);
    printNode(n2);
    bool result = true;
    auto it1 = n1;
    auto it2 = n2;
    while(true) {
        result &= it1->val == it2->val;
        it1 = it1->next;
        it2 = it2->next;
        if (it1 == nullptr && it2 == nullptr) {
            break;
        }
    }
    return result;
}

void runCase(std::vector<int> numbers1, std::vector<int> numbers2, std::vector<int> expectedResult) {
    static int caseNum = 1;
    ListNode* node1 = generateListNode(numbers1);
    ListNode* node2 = generateListNode(numbers2);

    Solution sol;
    auto solutionNode = sol.addTwoNumbers(node1, node2);
    bool isEqual = isNodeEquals(solutionNode, generateListNode(expectedResult));
    if (!isEqual) {
        std::cout << "Case " << caseNum << " failed\n";
        printNode(solutionNode);
    }

    delete node1;
    delete node2;
    delete solutionNode;
    caseNum++;
}


int main() {
    runCase({2, 4, 3}, {5, 6, 4}, {7, 0, 8});
    runCase({0}, {0}, {0});
    runCase({9,9,9,9,9,9,9}, {9,9,9,9}, {8,9,9,9,0,0,0,1});
    return 0;
}