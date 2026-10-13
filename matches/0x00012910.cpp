class Obj {
  public:
    char pad[0x20];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0x20;
}
