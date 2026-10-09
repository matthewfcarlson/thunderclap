extern void* operator_new(unsigned int);
struct Sub { void Init(); };
struct MPT { int vf; int a; int b; int c; float z; float w; Sub sub; void BaseInit(); };
class Factory { public: virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3(); virtual void q4(); virtual MPT* Create(); };
MPT* Factory::Create() {
 MPT* p = (MPT*)operator_new(0x24);
 if (p) {
  p->BaseInit();
  p->vf = 0x41b2e8;
  p->c = 0;
  p->z = -1.0f;
  p->w = 6.2831855f;
  p->sub.Init();
  p->b = 1;
  return p;
 }
 return 0;
}
