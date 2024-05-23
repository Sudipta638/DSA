// Print the MST as a tree-like structure
cout << "Minimum Spanning Tree (MST):" << endl;
for(auto edge : mst){
    cout << edge.first << " -- " << edge.second << endl;
}

// Print the graph with proper node weight and direction
cout << "Graph:" << endl;
for(auto edge : graph){
    cout << edge[0] << " --(" << edge[2] << ")-- " << edge[1] << endl;
}