class Obj {
  public:
    char pad[0xec];
    int value;
    int Get();
};

int Obj::Get() {
    return value;
}
