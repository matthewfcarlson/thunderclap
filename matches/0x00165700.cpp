class Obj {
  public:
    char pad[0x10];
    int mField;
    char Set(int v);
};
char Obj::Set(int v) {
    mField = v;
    return 1;
}
