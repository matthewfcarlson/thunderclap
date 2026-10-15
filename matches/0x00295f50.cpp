class Base {
  public:
    Base();
    virtual void f0();
    int pad;
};
class Part {
  public:
    void Copy(const Part&);
    char x[8];
};
class Node : public Base {
  public:
    Node(const Node& other) : Base() {
        a = other.a;
        b = other.b;
        p.Copy(other.p);
    }
    virtual void g();
    Part p;
    int a, b;
};
class LeafNode : public Node {
  public:
    LeafNode(const LeafNode&);
    virtual void h();
};
LeafNode::LeafNode(const LeafNode& other) : Node(other) {}