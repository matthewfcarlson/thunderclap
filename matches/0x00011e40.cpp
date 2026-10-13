class Obj {
  public:
    char pad[0x60];
    void* Get();
};

void* Obj::Get() {
    return (char*)pad + 0x60;
}
