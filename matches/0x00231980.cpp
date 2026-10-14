class Branch {
  public:
    void vfunc_7();
};
class Aux_231980 {
  public:
    void f();
};
class Node : public Branch {
    char pad[0x28 - sizeof(Branch)];

  public:
    void vfunc_7();
};
void Node::vfunc_7() {
    ((Aux_231980*)((char*)this + 0x28))->f();
    Branch::vfunc_7();
}