class Obj {
    char pad[0x24];
    int mValue;
    char mFlag;

  public:
    char Set(int v);
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
