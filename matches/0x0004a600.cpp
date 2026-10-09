typedef unsigned char u8;
struct A { void* f(); };
struct B { void* f(); };
struct Manager { char pad[0x1b28]; int field; };
struct CRageModeCondition {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6();
  virtual bool vfunc_7(void* arg);
  char pad[8];
  bool value;
};
bool CRageModeCondition::vfunc_7(void* arg) {
  A* a = (A*)arg;
  void* p = a->f();
  B* b = (B*)p;
  Manager* q = (Manager*)b->f();
  bool r = q->field != 0;
  return r == value;
}
