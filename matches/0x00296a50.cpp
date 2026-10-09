class Child { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(int,int); bool check(); };
class BranchNode { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(int,int,int); };
class VisibilityNode : public BranchNode {
public:
  virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(int,int,int);
  char pad[0x0c];
  unsigned char flags;
  char pad2[0x17];
  unsigned char enabled;
  char pad3[0x3];
  Child* child;
};
void VisibilityNode::f8(int a,int b,int c) {
  if (!(flags & 1)) {
    if (child && !child->check())
      child->f6(0,1);
    if (enabled == 1)
      BranchNode::f8(a,b,c);
  }
}
