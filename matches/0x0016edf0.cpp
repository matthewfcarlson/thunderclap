class Obj_16edf0 {
  public:
    char Set(int x);
    char pad[0x10];
    int mValue;
};

char Obj_16edf0::Set(int x) {
    mValue = x;
    return 1;
}