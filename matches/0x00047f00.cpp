class Obj_47f00 {
  public:
    char pad[0x18];
    char* Get();
};

char* Obj_47f00::Get() {
    return (char*)this + 0x18;
}
