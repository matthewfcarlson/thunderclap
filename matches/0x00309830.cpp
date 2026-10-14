class Obj_309830 {
  public:
    char pad[0x10];
    void foo();
    Obj_309830* target();
};
Obj_309830* Obj_309830::target() {
    foo();
    return (Obj_309830*)((char*)this + 0x10);
}