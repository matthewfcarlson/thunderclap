class Obj {
  public:
    int Fn();
};
extern Obj* gObj;
int __cdecl FUN_0024d210() {
    return gObj->Fn();
}
