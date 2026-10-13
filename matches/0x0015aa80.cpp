class Obj {
  public:
    char pad[0x88];
    Obj* Get();
};

Obj* Obj::Get() {
    return (Obj*)((char*)this + 0x88);
}
