class Obj {
  public:
    char pad[16];
};
char* __fastcall Target(Obj* p) {
    return (char*)p + 0x10;
}