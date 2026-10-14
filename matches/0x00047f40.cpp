class Obj_47f40 {
  public:
    char pad[0x10];
    char* Get();
};

char* Obj_47f40::Get() {
    return (char*)((char*)this + 0x10);
}
