class Obj {
  public:
    char pad[0x10];
    char* Get();
};

char* Obj::Get() {
    return (char*)((char*)this + 0x10);
}
