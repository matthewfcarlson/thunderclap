class Obj {
  public:
    char pad[0x98];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x98;
}
