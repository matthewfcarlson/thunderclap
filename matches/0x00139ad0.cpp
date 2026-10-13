class Obj {
  public:
    char pad[0x2c];
    int m;
    char Set(int v);
};
char Obj::Set(int v) {
    m = v;
    return 1;
}
