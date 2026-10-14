class Obj_139e00 {
  public:
    char pad[0x30];
    void* Get();
};
void* Obj_139e00::Get() {
    return (void*)((char*)this + 0x30);
}
