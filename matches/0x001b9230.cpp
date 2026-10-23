struct Vec {
    int a, b, c;
};
class Obj {
  public:
    Vec* get();
};
Obj* FUN_001c3d90();
Vec __stdcall target() {
    Obj* o = FUN_001c3d90();
    return *o->get();
}