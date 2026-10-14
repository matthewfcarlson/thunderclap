class Obj_12b240 {
  public:
    char pad[0x18];
    void* Get();
};
void* Obj_12b240::Get() {
    return (char*)this + 0x18;
}