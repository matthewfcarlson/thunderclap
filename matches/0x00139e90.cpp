class Obj {
  public:
    char pad[0x18];
};

void* __fastcall FUN_00139e90(Obj* self) {
    return (char*)self + 0x18;
}
