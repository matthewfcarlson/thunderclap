class Obj_89800 {
  public:
    char pad[0x60];
    char* Get();
};
char* Obj_89800::Get() {
    return (char*)this + 0x60;
}
