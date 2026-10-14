class Obj {
  public:
    char Set(int v);
    char pad[0x128];
    int mValue;
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
