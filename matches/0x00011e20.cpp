class Obj_11e20 {
  public:
    char pad[16];
    int* Get();
};
int* Obj_11e20::Get() {
    return (int*)((char*)this + 0x10);
}
