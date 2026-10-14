class Obj_11bc80 {
    char pad[0x24];
    int mValue;
    char mFlag;

  public:
    char Set(int v);
};

char Obj_11bc80::Set(int v) {
    mValue = v;
    return 1;
}
