class Obj_16ea50 {
  public:
    char pad[0x18];
    char* Get();
};

char* Obj_16ea50::Get() {
    return (char*)this + 0x18;
}
