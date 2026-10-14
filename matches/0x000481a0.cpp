class Obj_481a0 {
  public:
    char pad[0x10];
    void* Get();
};
void* Obj_481a0::Get() {
    return (char*)this + 0x10;
}