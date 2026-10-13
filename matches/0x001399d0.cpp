class Obj {
  public:
    char pad[0x10];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x10;
}
