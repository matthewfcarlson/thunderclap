class Obj {
  public:
    char pad[0x10];
    void* Get10();
};

void* Obj::Get10() {
    return (char*)this + 0x10;
}
