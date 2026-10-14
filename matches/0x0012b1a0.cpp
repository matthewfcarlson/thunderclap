class Obj_12b1a0 {
  public:
    char pad[0x10];
    void* Get10();
};

void* Obj_12b1a0::Get10() {
    return (char*)this + 0x10;
}
