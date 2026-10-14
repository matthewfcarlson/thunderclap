class Obj_1399d0 {
  public:
    char pad[0x10];
    void* Get();
};

void* Obj_1399d0::Get() {
    return (char*)this + 0x10;
}
