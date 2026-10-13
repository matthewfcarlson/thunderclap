class Obj {
  public:
    char pad[0x18];
    char* FUN_0017f460();
};
char* Obj::FUN_0017f460() {
    return (char*)((int)this + 0x18);
}