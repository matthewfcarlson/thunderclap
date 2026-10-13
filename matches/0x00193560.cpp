class Obj {
  public:
    char pad[0xe8];
    char* FUN_00193560();
};
char* Obj::FUN_00193560() {
    return (char*)this + 0xe8;
}