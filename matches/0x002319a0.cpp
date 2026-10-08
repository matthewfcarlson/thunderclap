class Branch { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void vfunc_5(); };
class Node : public Branch { char pad[0x24]; public: void vfunc_5(); };
struct Helper { void run(Node*); };
void Node::vfunc_5() { Branch::vfunc_5(); ((Helper*)((char*)this + 0x28))->run(this); }
