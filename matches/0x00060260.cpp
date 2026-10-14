class Obj_60260 {
  public:
    char pad[0x38];
    char* GetSub();
};
char* Obj_60260::GetSub() {
    return (char*)this + 0x38;
}