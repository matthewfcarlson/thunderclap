class Obj {
  public:
    char pad[0x30];
    void* mPtr;
};
void* __fastcall FUN_0015b6e0(Obj* self) {
    return (char*)self + 0x30;
}
