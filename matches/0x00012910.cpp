class Obj_12910 {
  public:
    char pad[0x20];
    void* Get();
};
void* Obj_12910::Get() {
    return (char*)this + 0x20;
}
