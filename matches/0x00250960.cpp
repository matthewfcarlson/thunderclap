class Obj {
  public:
    char pad[8];
    char* Get();
};

char* Obj::Get() {
    return pad + 8;
}
