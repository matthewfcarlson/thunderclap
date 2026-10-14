class Obj_15ad00 {
  public:
    char pad[0x90];
    void* Get();
};

void* Obj_15ad00::Get() {
    return (char*)this + 0x90;
}
