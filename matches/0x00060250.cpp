class Obj_60250 {
  public:
    char pad[0x30];
    void* Get();
};

void* Obj_60250::Get() {
    return (char*)this + 0x30;
}
