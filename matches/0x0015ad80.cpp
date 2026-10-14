class Obj {
  public:
    char pad[0x10];
    int m10;
    char SetX(int value);
};

char Obj::SetX(int value) {
    m10 = value;
    return 1;
}
