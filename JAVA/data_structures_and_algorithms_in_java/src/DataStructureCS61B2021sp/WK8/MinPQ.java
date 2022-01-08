package DataStructureCS61B2021sp.WK8;

public interface MinPQ<Item> {
    public void add(Item x);
    //O(logN)
    public Item getSmallest();
    //O(1)
    public Item removeSmallest();
    //O(logN)
    public int size();
}

//Adjacent matrix
//Edge sets
//Adjacent lists