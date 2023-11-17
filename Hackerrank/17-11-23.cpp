//SPARSE ARRAYS

/*
There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.

Example



There are  instances of '',  of '' and  of ''. For each query, add an element to the return array, .

Function Description

Complete the function matchingStrings in the editor below. The function must return an array of integers representing the frequency of occurrence of each query string in stringList.

matchingStrings has the following parameters:

string stringList[n] - an array of strings to search
string queries[q] - an array of query strings
Returns

int[q]: an array of results for each query
Input Format

The first line contains and integer , the size of .
Each of the next  lines contains a string .
The next line contains , the size of .
Each of the next  lines contains a string .
*/

// #include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cctype>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    // Create a map to store the count of each string in stringList
    unordered_map<string, int> countMap;

    // Count occurrences of strings in stringList
    for (const string& s : stringList) {
        countMap[s]++;
    }

    // Create a vector to store the results
    vector<int> results;

    // Count occurrences of each query in the map
    for (const string& query : queries) {
        // If the query is found in the map, add its count to results
        if (countMap.find(query) != countMap.end()) {
            results.push_back(countMap[query]);
        } else {
            // If the query is not found, add 0 to results
            results.push_back(0);
        }
    }

    return results;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string stringList_count_temp;
    getline(cin, stringList_count_temp);

    int stringList_count = stoi(ltrim(rtrim(stringList_count_temp)));

    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++) {
        string stringList_item;
        getline(cin, stringList_item);

        stringList[i] = stringList_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(stringList, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}




//QUEUE USING TWO STACKS
/*
A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
Input Format

The first line contains a single integer, , denoting the number of queries.
Each line  of the  subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query , but only query  is followed by an additional space-separated value, , denoting the value to be enqueued.

Constraints

It is guaranteed that a valid answer always exists for each query of type .
Output Format

For each query of type , print the value of the element at the front of the queue on a new line.

Sample Input

STDIN   Function
-----   --------
10      q = 10 (number of queries)
1 42    1st query, enqueue 42
2       dequeue front element
1 14    enqueue 42
3       print the front element
1 28    enqueue 28
3       print the front element
1 60    enqueue 60
1 78    enqueue 78
2       dequeue front element
2       dequeue front element
Sample Output

14
14
Explanation

Perform the following sequence of actions:

Enqueue ; .
Dequeue the value at the head of the queue, ; .
Enqueue ; .
Print the value at the head of the queue, ; .
Enqueue ; .
Print the value at the head of the queue, ; .
Enqueue ; .
Enqueue ; .
Dequeue the value at the head of the queue, ; .
Dequeue the value at the head of the queue, ; 
*/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stackNewestOnTop, stackOldestOnTop;

public:
    void enqueue(int x) {
        stackNewestOnTop.push(x);
    }

    void dequeue() {
        shiftStacks();
        stackOldestOnTop.pop();
    }

    int front() {
        shiftStacks();
        return stackOldestOnTop.top();
    }

private:
    void shiftStacks() {
        if (stackOldestOnTop.empty()) {
            while (!stackNewestOnTop.empty()) {
                stackOldestOnTop.push(stackNewestOnTop.top());
                stackNewestOnTop.pop();
            }
        }
    }
};

int main() {
    MyQueue q;

    int qCount;
    cin >> qCount;

    for (int i = 0; i < qCount; i++) {
        int queryType;
        cin >> queryType;

        switch (queryType) {
            case 1:
                int x;
                cin >> x;
                q.enqueue(x);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << q.front() << endl;
                break;
        }
    }

    return 0;
}


//INSERT A NODE INTO A SORTED DOUBLY LINKED LIST
/*
Given a reference to the head of a doubly-linked list and an integer, , create a new DoublyLinkedListNode object having data value  and insert it at the proper location to maintain the sort.

Example

 refers to the list 

Return a reference to the new list: .

Function Description

Complete the sortedInsert function in the editor below.

sortedInsert has two parameters:

DoublyLinkedListNode pointer head: a reference to the head of a doubly-linked list

int data: An integer denoting the value of the  field for the DoublyLinkedListNode you must insert into the list.

Returns

DoublyLinkedListNode pointer: a reference to the head of the list
Note: Recall that an empty list (i.e., where ) and a list with one element are sorted lists.

Input Format

The first line contains an integer , the number of test cases.

Each of the test case is in the following format:

The first line contains an integer , the number of elements in the linked list.
Each of the next  lines contains an integer, the data for each node of the linked list.
The last line contains an integer, , which needs to be inserted into the sorted doubly-linked list.
Constraints

Sample Input

STDIN   Function
-----   --------
1       t = 1
4       n = 4
1       node data values = 1, 3, 4, 10
3
4
10
5       data = 5
Sample Output

1 3 4 5 10
Explanation

The initial doubly linked list is:  .

The doubly linked list after insertion is: 
*/

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);

    // If the list is empty or the new node is smaller than the head
    if (!llist || data < llist->data) {
        newNode->next = llist;
        if (llist) {
            llist->prev = newNode;
        }
        return newNode;
    }

    DoublyLinkedListNode* current = llist;

    // Traverse the list to find the correct position
    while (current->next && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return llist;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}



//QHEAP1
/*
This question is designed to help you get a better understanding of basic heap operations.

There are  types of query:

" " - Add an element  to the heap.
" " - Delete the element  from the heap.
"" - Print the minimum of all the elements in the heap.
NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any instant, only distinct elements will be in the heap.

Input Format

The first line contains the number of queries, .
Each of the next  lines contains one of the  types of query.

Constraints


Output Format

For each query of type , print the minimum value on a single line.

Sample Input

STDIN       Function
-----       --------
5           Q = 5
1 4         insert 4
1 9         insert 9
3           print minimum
2 4         delete 4
3           print minimum
Sample Output

4  
9 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> heap;
    make_heap(heap.begin(), heap.end(), greater<int>());

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // Insert element into the heap
            int element;
            cin >> element;
            heap.push_back(element);
            push_heap(heap.begin(), heap.end(), greater<int>());
        } else if (type == 2) {
            // Delete element from the heap
            int element;
            cin >> element;
            auto it = find(heap.begin(), heap.end(), element);
            heap.erase(it);
            make_heap(heap.begin(), heap.end(), greater<int>());
        } else if (type == 3) {
            // Print the minimum value
            cout << heap.front() << endl;
        }
    }

    return 0;
}


//TREE: POSTORDER TRAVERSAL
/*
Complete the  function in the editor below. It received  parameter: a pointer to the root of a binary tree. It must print the values in the tree's postorder traversal as a single line of space-separated values.

Input Format

Our test code passes the root node of a binary tree to the  function.

Constraints

 Nodes in the tree  

Output Format

Print the tree's postorder traversal as a single line of space-separated values.

Sample Input

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4
Sample Output

4 3 6 5 2 1 
Explanation

The postorder traversal is shown.
*/

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node *insert(Node *root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node *cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void postOrder(Node *root) {
        if (root == NULL) {
            return;
        }

        // Traverse the left subtree
        postOrder(root->left);

        // Traverse the right subtree
        postOrder(root->right);

        // Print the data of the current node
        cout << root->data << " ";
    }
}; // End of Solution

int main() {

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.postOrder(root);
    return 0;
}
