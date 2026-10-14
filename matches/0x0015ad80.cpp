class Obj_15ad80 {
  public:
    char pad[0x10];
    int m10;
    char SetX(int value);
};

char Obj_15ad80::SetX(int value) {
    m10 = value;
    return 1;
}
