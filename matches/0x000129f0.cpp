class Obj {
  public:
    char pad[0x18];
    void* GetPtr();
};

void* Obj::GetPtr() {
    return (char*)this + 0x18;
}
