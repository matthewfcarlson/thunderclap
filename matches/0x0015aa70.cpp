class Obj_15aa70 {
  public:
    char pad[0x80];
    char* Get();
};
char* Obj_15aa70::Get() {
    return (char*)((char*)this + 0x80);
}
