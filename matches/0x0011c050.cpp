class Obj_11c050 {
  public:
    char f(int value);
    char pad[0x24];
    int m24;
};

char Obj_11c050::f(int value) {
    m24 = value;
    return 1;
}