class Obj {
  public:
    char pad[0x90];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x90;
}
