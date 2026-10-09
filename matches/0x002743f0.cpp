class D { public: virtual int s0(); virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6(); virtual int s7(); int Helper(); };
class Q { public: virtual void s0(); virtual void s1(); };
class P { public: int pad0; Q q; int pad8; D* d; int pad10; int pad14; int f18; };
class DriveRequest {
public:
  virtual int v0();
  virtual int v1();
  virtual int v2();
  virtual int v3();
  virtual int vfunc_4();
  virtual int v5();
  char pad[4];
  P* mP;
};
int DriveRequest::vfunc_4() {
  D* d = mP->d;
  int a = d->s7();
  int b = d->Helper();
  mP->q.s0();
  mP->f18 = b;
  mP->q.s1();
  return a;
}
