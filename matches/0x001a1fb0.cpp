class Obj {
  public:
    char pad[0x18];
    char* Get();
};
char* Obj::Get() {
    return pad + 0x18;
}
