class Obj_15b610 {
  public:
    char pad[0x48];
    char* Get();
};

char* Obj_15b610::Get() {
    return (char*)this + 0x48;
}
