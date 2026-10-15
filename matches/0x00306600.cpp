class Node;
struct List {
    Node** first;
    Node** last;
};
class Node {
  public:
    char pad[8];
    int value;
    char pad2[8];
    List* children;
    void Set(int v);
};
void Node::Set(int v) {
    value = v;
    if (children) {
        for (unsigned i = 0; i < (unsigned)(children->last - children->first); ++i)
            children->first[i]->Set(v);
    }
}