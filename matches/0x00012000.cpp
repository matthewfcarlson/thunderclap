class Obj {
  public:
    char pad[0x2c];
    int value;
    int Get();
};

int Obj::Get() {
    return value;
}
