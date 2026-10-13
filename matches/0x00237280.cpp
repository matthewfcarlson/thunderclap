class Obj {
  public:
    char pad[0x28];
    char* Get();
};

char* Obj::Get() {
    return (char*)((char*)pad + 0x28);
}
