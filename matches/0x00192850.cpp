class Obj {
  public:
    char pad[0x18];
    Obj* Get();
};
Obj* Obj::Get() {
    return (Obj*)((char*)this + 0x18);
}
