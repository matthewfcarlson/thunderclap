class Obj {
  public:
    char pad[0x60];
};

void* __fastcall FUN_00012990(Obj* self) {
    return (char*)self + 0x60;
}
