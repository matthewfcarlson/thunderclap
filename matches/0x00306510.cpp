class Node;
struct Vec {
    Node** first;
    Node** last;
    unsigned size() const { return ((char*)last - (char*)first) >> 2; }
    Node* operator[](unsigned i) const { return first[i]; }
};
class Node {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void action();
    char pad[12];
    void* flag;
    Vec* children;
    void run();
};
void Node::run() {
    if (flag)
        action();
    if (children) {
        for (unsigned i = 0; i < children->size(); ++i)
            (*children)[i]->run();
    }
}