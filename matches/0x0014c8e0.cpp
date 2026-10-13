class Obj {
  public:
    char pad[0x18];
    void* p;
    void* FUN_0014c8e0();
};
void* Obj::FUN_0014c8e0() {
    return (char*)this + 0x18;
}
