class Obj_10c5b0 {
  public:
    char Set(int x);
    char pad[0x18];
    int mValue;
};

char Obj_10c5b0::Set(int x) {
    mValue = x;
    return 1;
}
