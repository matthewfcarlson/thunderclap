class Obj_16eaf0 {
  public:
    char pad[0x18];
    char* Get();
};
char* Obj_16eaf0::Get() {
    return (char*)((char*)this + 0x18);
}