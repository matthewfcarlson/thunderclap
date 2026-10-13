class Obj {
  public:
    char Pad[0x2c];
    int m2c;
    char Set(int a);
};

char Obj::Set(int a) {
    m2c = a;
    return 1;
}
