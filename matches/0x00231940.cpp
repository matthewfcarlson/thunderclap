extern "C" char DAT_00427688[];
class Base {
  public:
    void Init(int);
    char pad[0x28];
};
class Sub {
  public:
    void Init();
};
class Node {
  public:
    Base b;
    Sub sub;
    Node* InitNode();
};
Node* Node::InitNode() {
    b.Init(1);
    *(int*)this = ((int)DAT_00427688);
    sub.Init();
    return this;
}
