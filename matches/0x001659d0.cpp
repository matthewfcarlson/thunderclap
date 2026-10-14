class Obj {
  public:
    char m0;
    char m1;
    char pad[8];
    int mField;
    char Set(int v);
};

char Obj::Set(int v) {
    mField = v;
    return 1;
}
