class Obj {
  public:
    char pad[0x2c];
    int m2c;
    char Set(int n);
};
char Obj::Set(int n) {
    m2c = n;
    return 1;
}
