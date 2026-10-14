class Obj_1800c0 {
  public:
    char pad[0x60];
    void* Get();
};
void* Obj_1800c0::Get() {
    return (char*)this + 0x60;
}
