class Obj {
  public:
    char pad[0x4c];
    int mValue;
    char Set(int v);
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
