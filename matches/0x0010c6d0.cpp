class Obj {
  public:
    char Get();
};
char Obj::Get() {
    return *(char*)((char*)this + 0x21);
}