class Obj {
  public:
    char pad[0x24];
    char* Get();
};

char* Obj::Get() {
    return pad + 0x24;
}
