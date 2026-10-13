class Obj {
  public:
    char pad[0x2c];
    int m2c;
    char Set(int v);
};

char Obj::Set(int v) {
    m2c = v;
    return 1;
}