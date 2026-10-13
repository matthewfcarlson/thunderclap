class Obj {
  public:
    char pad[0x18];
    void* Data();
};
void* Obj::Data() {
    return (void*)((char*)this + 0x18);
}
