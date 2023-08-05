#include "dfs.h"
#include <vector>
#include <stack>

// Function to perform Depth-First Search on a graph
std::vector<int> dfs(const Graph& graph, int startVertex) {
    int numVertices = graph.size();
    std::vector<bool> visited(numVertices, false);
    std::vector<int> traversalOrder;
    std::stack<int> st;

    st.push(startVertex);

    while (!st.empty()) {
        int currentVertex = st.top();
        st.pop();

        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            traversalOrder.push_back(currentVertex);

            for (int neighbor : graph[currentVertex]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }

    return traversalOrder;
}

// Big O Notation:
// - Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
// - Space Complexity: O(V), where V is the number of vertices
