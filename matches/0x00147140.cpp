class Obj_147140 {
  public:
    char Pad[0x2c];
    int Value;
    char Target(int x);
};

char Obj_147140::Target(int x) {
    Value = x;
    return 1;
}
