class Obj {
  public:
    char pad[0x20];
    char* Get();
};
char* Obj::Get() {
    return (char*)this + 0x20;
}