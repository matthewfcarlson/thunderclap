class Obj {
  public:
    char pad[12];
    int mVal;
    char Set(int v);
};

char Obj::Set(int v) {
    mVal = v;
    return 1;
}
