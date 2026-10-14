class Obj {
  public:
    char pad[0xa4];
    int mValue;
    char Set(int v);
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
