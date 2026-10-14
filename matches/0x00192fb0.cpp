class Obj_192fb0 {
  public:
    char pad[0x20];
    char* Get();
};
char* Obj_192fb0::Get() {
    return (char*)this + 0x20;
}