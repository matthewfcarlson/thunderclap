class Obj {
  public:
    char Pad[0x2c];
    int Value;
    char Target(int x);
};

char Obj::Target(int x) {
    Value = x;
    return 1;
}
