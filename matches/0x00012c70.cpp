class Obj {
  public:
    char pad[0x60];
    char* FUN_00012c70();
};

char* Obj::FUN_00012c70() {
    return (char*)this + 0x60;
}
