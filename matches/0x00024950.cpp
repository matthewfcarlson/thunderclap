class Obj {
  public:
    char pad[0x2c4];
    int field;
};
Obj* __stdcall getObj();
void __stdcall FUN_00024950(int x) {
    Obj* p = getObj();
    p->field = x;
}