class Obj_1928a0 {
  public:
    char pad[0x30];
    void* Get();
};
void* Obj_1928a0::Get() {
    return (void*)((char*)this + 0x30);
}
