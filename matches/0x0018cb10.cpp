class Obj {
  public:
    char Pad[0x1c];
    int mVal;
    char Set(int x);
};
char Obj::Set(int x) {
    mVal = x;
    return 1;
}
