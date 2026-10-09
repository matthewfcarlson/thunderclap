class Obj { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
class Helper { public: void helper(void*, int, int, int); };
class CMotionTrailQueue {
public:
  virtual void f0();
  virtual void f1();
  virtual void f2();
  virtual void f3();
  virtual void f4();
  virtual void f5();
  virtual void f6();
  virtual void f7();
  virtual void vfunc_8(int a, int b);
  char pad[0x44];
  char *items;
  char pad2[0x10];
  char *flags;
};
void CMotionTrailQueue::vfunc_8(int a, int b) {
  for (int i = 0; i < 6; ++i) {
    if (flags[i * 8 + 4]) {
      if (a) {
        ((Helper *)a)->helper(this, i, 0, b);
      } else {
        Obj *o = *(Obj **)(items + i * 16);
        o->f6();
      }
    }
  }
}
