class Obj_15b6c0 {
  public:
    char pad[0x20];
    void* Get();
};
void* Obj_15b6c0::Get() {
    return (char*)this + 0x20;
}