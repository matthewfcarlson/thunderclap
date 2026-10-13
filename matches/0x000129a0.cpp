class Obj {
  public:
    char pad[0x68];
    char* Get();
};
char* Obj::Get() {
    return (char*)this + 0x68;
}