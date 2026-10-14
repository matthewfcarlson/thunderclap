class Obj_12900 {
  public:
    char pad[0x18];
    char* Get();
};
char* Obj_12900::Get() {
    return (char*)this + 0x18;
}