class Obj {
  public:
    char pad[0x10];
    int m10;
    char Set(int v);
};
char Obj::Set(int v) {
    m10 = v;
    return 1;
}