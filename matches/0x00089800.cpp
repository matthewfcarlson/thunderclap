class Obj {
  public:
    char pad[0x60];
    char* Get();
};
char* Obj::Get() {
    return (char*)this + 0x60;
}
