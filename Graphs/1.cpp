#include <iostream>
#include <vector>

using namespace std;

void createAdjList(const vector<vector<int>>& data, vector<vector<int>>& adjlist) {
    // Find the maximum node value to determine the size of the adjacency list
    int maxNode = 0;
    for (const vector<int>& vec : data) {
        maxNode = max(maxNode, max(vec[0], vec[1]));
    }

    // Resize adjlist to fit all nodes
    adjlist.resize(maxNode + 1);

    // Populate the adjacency list
    for (const vector<int>& vec : data) {
        int u = vec[0];
        int v = vec[1];
        adjlist[u].push_back(v);
    }
}

int main() {
    vector<vector<int>> data = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 0},
        {2, 3},
        {3, 3}
    };

    vector<vector<int>> adjlist;
    createAdjList(data, adjlist);

    // Print the adjacency list
    for (int i = 0; i < adjlist.size(); ++i) {
        cout << "Adjacency list of vertex " << i << ":";
        for (int v : adjlist[i]) {
            cout << " -> " << v;
        }
        cout << endl;
    }

    return 0;
}
