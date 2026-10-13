class Obj {
  public:
    char* Get10();
};
char* Obj::Get10() {
    return (char*)this + 0x10;
}