class Obj_16ef00 {
  public:
    char pad[0x18];
    void* Get();
};
void* Obj_16ef00::Get() {
    void* p = (char*)this + 0x18;
    return p;
}