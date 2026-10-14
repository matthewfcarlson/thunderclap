class Obj_12740 {
  public:
    char pad[0x18];
    char* Get();
};
char* Obj_12740::Get() {
    return (char*)this + 0x18;
}