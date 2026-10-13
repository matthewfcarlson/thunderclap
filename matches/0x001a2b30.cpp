class Obj {
  public:
    char pad[0x154];
    int value;
    int Get();
};

int Obj::Get() {
    return value;
}
