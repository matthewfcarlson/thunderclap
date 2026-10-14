class Obj_1657c0 {
  public:
    char pad[0x10];
    void* Get();
};
void* Obj_1657c0::Get() {
    return (void*)((char*)this + 0x10);
}
