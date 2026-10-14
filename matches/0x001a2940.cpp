class Obj {
  public:
    char pad[0x114];
    int mVal;
    char Set(int x);
};
char Obj::Set(int x) {
    mVal = x;
    return 1;
}
