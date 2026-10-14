class Obj_5a300 {
  public:
    char pad[0x18];
    void* Get();
};

void* Obj_5a300::Get() {
    return (char*)this + 0x18;
}