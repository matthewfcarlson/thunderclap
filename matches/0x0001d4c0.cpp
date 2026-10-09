class Obj { public: virtual void F(); virtual void G(); };
class Helper { public: float Get(); };
class Base { public: Base(); virtual void Z(); };
class CAction : public Base {
public:
  CAction(Obj* o);
  virtual void A();
  virtual void B();
  char pad[0x18];
  Obj* ref;
};
CAction::CAction(Obj* o) : Base() {
  ref = 0;
  if (o) o->F();
  if (ref) ref->G();
  ref = o;
}
class CAutoTargetAction : public CAction {
public:
  CAutoTargetAction(Helper* h, Obj* o);
  virtual void C();
  virtual void D();
  Helper* x;
  int y;
  int z;
  float f;
};
CAutoTargetAction::CAutoTargetAction(Helper* h, Obj* o) : CAction(o) {
  y = 0;
  z = 0;
  x = h;
  f = h->Get();
}
