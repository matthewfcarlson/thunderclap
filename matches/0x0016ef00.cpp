class Obj {
  public:
    char pad[0x18];
    void* Get();
};
void* Obj::Get() {
    void* p = (char*)this + 0x18;
    return p;
}