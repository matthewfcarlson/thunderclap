class Obj_12ef0 {
  public:
    char pad[0x58];
    char* Get();
};

char* Obj_12ef0::Get() {
    return (char*)this + 0x58;
}
