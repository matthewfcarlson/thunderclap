class Obj {
  public:
    char pad[0x68];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x68;
}
