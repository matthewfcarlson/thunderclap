class Obj {
  public:
    char pad[0x30];
    char* Get();
};
char* Obj::Get() {
    return (char*)this + 0x30;
}