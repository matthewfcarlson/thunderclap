class Obj_15b470 {
  public:
    char pad[0x50];
    char* Get();
};
char* Obj_15b470::Get() {
    return (char*)((char*)this + 0x50);
}