class Obj {
  public:
    char pad[0x48];
    char* Get();
};

char* Obj::Get() {
    return (char*)this + 0x48;
}
