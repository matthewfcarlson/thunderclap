class Obj_12120 {
  public:
    char pad[0x48];
    char* Get();
};

char* Obj_12120::Get() {
    return (char*)this + 0x48;
}
