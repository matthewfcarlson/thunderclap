class Obj {
  public:
    char pad[0x18];
    char* mPtr;
    char** Get();
};

char** Obj::Get() {
    return &mPtr;
}
