package DataStructureCS61B2021sp.WK8;

import java.util.ArrayList;
import java.util.List;

public class myGraph {
    private final int V;
    private List<Integer>[] adj;

    public myGraph(int V){
        this.V = V;
        adj = (List<Integer>[]) new ArrayList[V];
        for(int v = 0; v < V; v++) {
            adj[v] = new ArrayList<Integer>();
        }
    }

    public void addEdge(int v, int w){
        adj[v].add(w);
        adj[w].add(v);
    }

    public Iterable<Integer> adj(int v){
        return adj[v];
    }
}
