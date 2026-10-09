typedef unsigned int u32;
struct Buf { char d[16]; void Fn(u32); };
struct RotationChannel {
  virtual void f0();
  virtual void f1();
  virtual void f2();
  virtual void f3();
  virtual void f4();
  virtual void f5(u32, void*);
};
struct QuaternionChannel : RotationChannel {
  virtual void vfunc_6(u32, u32);
};
void QuaternionChannel::vfunc_6(u32 a, u32 b) {
  Buf buf;
  f5(a, buf.d);
  buf.Fn(b);
}
