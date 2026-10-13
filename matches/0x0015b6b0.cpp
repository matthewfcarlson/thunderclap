class Obj {
  public:
    char pad[0x18];
    void* Get18();
};
void* Obj::Get18() {
    return (void*)((char*)this + 0x18);
}