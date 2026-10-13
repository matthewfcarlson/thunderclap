class Obj {
  public:
    char pad[0x214];
    int value;
    int Get();
};

int Obj::Get() {
    return value;
}
