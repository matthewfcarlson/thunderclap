class Obj {
  public:
    char Pad[0x10];
    int m10;
    char Set(int x);
};
char Obj::Set(int x) {
    m10 = x;
    return 1;
}
