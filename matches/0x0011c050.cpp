class Obj {
  public:
    char f(int value);
    char pad[0x24];
    int m24;
};

char Obj::f(int value) {
    m24 = value;
    return 1;
}