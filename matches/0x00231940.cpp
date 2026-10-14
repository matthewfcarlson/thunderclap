extern "C" char DAT_00427688[];
class Base_231940 {
  public:
    void Init(int);
    char pad[0x28];
};
class Sub_231940 {
  public:
    void Init();
};
class Node {
  public:
    Base_231940 b;
    Sub_231940 sub;
    Node* InitNode();
};
Node* Node::InitNode() {
    b.Init(1);
    *(int*)this = ((int)DAT_00427688);
    sub.Init();
    return this;
}
