class Obj {
  public:
    char m[24];
    char* Get();
};

char* Obj::Get() {
    return m + 0x18;
}
