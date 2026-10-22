class Node {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Source {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Node* Get();
};
struct Input {
    char pad[0x40];
    Source* source;
};
class DrawableHierarchy_2970e0 {
  public:
    DrawableHierarchy_2970e0(Input*);
    virtual void vf();
    char pad[0x3c];
};
class Scenegraph : public DrawableHierarchy_2970e0 {
  public:
    Scenegraph(Input*);
    virtual void vf();
    Node* node;
};
Scenegraph::Scenegraph(Input* src) : DrawableHierarchy_2970e0(src) {
    node = 0;
    if (src->source) {
        Node* p = src->source->Get();
        if (p)
            p->AddRef();
        if (node)
            node->Release();
        node = p;
    }
}