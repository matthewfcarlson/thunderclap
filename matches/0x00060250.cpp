class Obj {
  public:
    char pad[0x30];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x30;
}
