class Obj {
  public:
    char pad[0x10];
    void* Get();
};
void* Obj::Get() {
    char* p = (char*)this + 0x10;
    return p;
}
