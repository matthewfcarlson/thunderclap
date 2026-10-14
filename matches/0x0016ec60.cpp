class Obj {
  public:
    char Pad[0xc];
    int mVal;
    char Set(int v);
};
char Obj::Set(int v) {
    mVal = v;
    return 1;
}