class Obj_47d30 {
  public:
    char pad[16];
    void* Get();
};
void* Obj_47d30::Get() {
    return (char*)this + 16;
}