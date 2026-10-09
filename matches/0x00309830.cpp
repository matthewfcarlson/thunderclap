class Obj {
  public:
    char pad[0x10];
    void foo();
    Obj* target();
};
Obj* Obj::target() {
    foo();
    return (Obj*)((char*)this + 0x10);
}