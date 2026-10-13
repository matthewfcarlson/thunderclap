class Obj {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0xc - 4];
    int mField;
    char Set(int x);
};
char Obj::Set(int x) {
    mField = x;
    return 1;
}
