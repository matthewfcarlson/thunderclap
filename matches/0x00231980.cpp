class Branch {
  public:
    void vfunc_7();
};
class Aux {
  public:
    void f();
};
class Node : public Branch {
    char pad[0x28 - sizeof(Branch)];

  public:
    void vfunc_7();
};
void Node::vfunc_7() {
    ((Aux*)((char*)this + 0x28))->f();
    Branch::vfunc_7();
}