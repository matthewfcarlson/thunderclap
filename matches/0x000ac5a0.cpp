extern int vtable;
class Ref { public: virtual void f0(); virtual void f1(); };
class CNISCamera {
public:
  virtual void f0();
  virtual void f1();
  virtual CNISCamera* vfunc_2(unsigned char flag);
  char pad[0x16c];
  Ref* mRef;
};
void __fastcall init(CNISCamera*);
void __cdecl thunk(CNISCamera*);
CNISCamera* CNISCamera::vfunc_2(unsigned char flag) {
  *(volatile int*)this = (int)&vtable;
  Ref* r = *(Ref* volatile*)&mRef;
  if (r) { r->f1(); mRef = 0; }
  init(this);
  if (flag & 1) thunk(this);
  return this;
}
