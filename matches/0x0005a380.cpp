class Obj_5a380 {
  public:
    char pad[0x18];
    void* Data();
};
void* Obj_5a380::Data() {
    return (void*)((char*)this + 0x18);
}
