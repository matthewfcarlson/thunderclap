class Obj_12400 {
  public:
    char pad[0x18];
    void* Get();
};
void* Obj_12400::Get() {
    return (char*)this + 0x18;
}
