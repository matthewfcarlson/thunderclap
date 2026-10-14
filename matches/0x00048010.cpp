class Obj_48010 {
  public:
    char pad[16];
    void* Get();
};
void* Obj_48010::Get() {
    return (char*)this + 16;
}
