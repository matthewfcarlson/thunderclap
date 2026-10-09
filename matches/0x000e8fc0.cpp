class Child { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(int); };
class FELayout { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); };
class VScroll : public FELayout {
public:
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(int); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
  virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21();
  void helper(int,int);
  char pad[0x240];
  Child *child;
  int val248;
  char pad3[0x1c];
  int val268;
};
void VScroll::v8(int p) {
  switch(p) {
  case 1: {
    int x = val268;
    if (val248 != x) helper(x, 1);
    break;
  }
  case 2:
    if (val248 != 0) helper(0, 2);
    break;
  }
  if (child) child->f13(p);
}
