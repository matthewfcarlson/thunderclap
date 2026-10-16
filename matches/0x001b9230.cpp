struct Vec {
    int a, b, c;
};
class Obj {
  public:
    Vec* get();
};
Obj* make();
Vec __stdcall target() {
    Obj* o = make();
    return *o->get();
}