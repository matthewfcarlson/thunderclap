class Obj {
  public:
    char pad[0x20];
    int m20;
    char SetFlag(int value);
};

char Obj::SetFlag(int value) {
    m20 = value;
    return 1;
}
