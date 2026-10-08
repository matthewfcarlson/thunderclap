typedef unsigned char u8;
struct Obj { char pad[0x15]; u8 flag; };
struct PropActorToPropAction {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void vfunc_4();
  virtual void v5();
  void FUN_00181d30();
  char pad[0x18];
  Obj* mObj;
};
void PropActorToPropAction::vfunc_4() {
  if (mObj->flag) FUN_00181d30();
}
