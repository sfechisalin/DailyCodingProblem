/*
    A network consists of nodes labeled 0 to N. You are given a list of edges (a, b, t), describing the time t it takes for a message to be sent from node a to node b. Whenever a node receives a message, it immediately passes the message on to a neighboring node, if possible.

    Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node 0.

    For example, given N = 5, and the following edges:

    edges = [
        (0, 1, 5),
        (0, 2, 3),
        (0, 5, 4),
        (1, 3, 8),
        (2, 3, 1),
        (3, 5, 10),
        (3, 4, 5)
    ]
    You should return 9, because propagating the message from 0 -> 2 -> 3 -> 4 will take that much time.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Connection {
private:
    int startNode;
    int endNote;
    int time;
public:
    Connection (int _startNode, int _endNode, int _time) : startNode {_startNode}, endNote {_endNode}, time {_time} {
    }

    int getStartNode() {return startNode;}
    int getEndNode() {return endNote;}
    int getTime() {return time;}
};

class Solution {
private:
    vector<int> distance;
    vector<vector<pair<int, int>>> _connections;
    priority_queue<pair<int,int>, vector<pair<int, int>>> queue;

    void preProcess(int n, vector<Connection> &connections) {
        distance.resize(n + 1, 0x3f3f3f3);
        _connections.resize(n + 1, vector<pair<int, int>>());
        for (Connection &connection : connections) {
            _connections[connection.getStartNode()].push_back({connection.getEndNode(), connection.getTime()});
        }
    }

    int timeToReachEveryNode(int startNode) {
       queue.push({0, startNode});
       distance[startNode] = 0;

       while (!queue.empty()) {
           auto [dist, node] = queue.top();
           queue.pop();

           if (distance[node] < dist) {
               continue;
           }

           for (auto &next : _connections[node])
                if (distance[next.first] > dist + next.second) {
                    distance[next.first] = dist + next.second;
                    queue.push({dist + next.second, next.first});
                }

       }

       return *max_element(distance.begin(), distance.end());
    }

public:


    int getTimeToReachEveryNode(int startNode, int n, vector<Connection> &connections) {
        preProcess(n, connections);
        return timeToReachEveryNode(startNode);
    }
};


int main() {
    vector<Connection> connections {
        Connection(0, 1, 5),
        Connection(0, 2, 3),
        Connection(0, 5, 4),
        Connection(1, 3, 8),
        Connection(2, 3, 1),
        Connection(3, 5, 10),
        Connection(3,4, 5)
    };


    Solution s;
    cout << s.getTimeToReachEveryNode(0, 5, connections);

    return 0;
}
