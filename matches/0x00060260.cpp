class Obj {
  public:
    char pad[0x38];
    char* GetSub();
};
char* Obj::GetSub() {
    return (char*)this + 0x38;
}