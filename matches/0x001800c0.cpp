class Obj {
  public:
    char pad[0x60];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0x60;
}
