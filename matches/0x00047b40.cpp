class Obj {
  public:
    char Set(int v);
    char pad[0x14];
    int mField;
};

char Obj::Set(int v) {
    mField = v;
    return 1;
}
