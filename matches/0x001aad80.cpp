class Obj {
  public:
    char m[0x18];
    char* Get();
};
char* Obj::Get() {
    return m + 0x18;
}
