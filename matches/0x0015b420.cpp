class Obj_15b420 {
  public:
    char pad[0x30];
    char* Get();
};
char* Obj_15b420::Get() {
    return (char*)this + 0x30;
}