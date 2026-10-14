class Obj_12f00 {
  public:
    char pad[0x68];
    char* Get();
};
char* Obj_12f00::Get() {
    return (char*)this + 0x68;
}