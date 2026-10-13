class Obj {
  public:
    char pad[0x40];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x40;
}
