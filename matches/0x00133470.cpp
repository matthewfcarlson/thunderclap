class Obj_133470 {
  public:
    char pad[0xc];
    int mValue;
    char Set(int value);
};

char Obj_133470::Set(int value) {
    mValue = value;
    return 1;
}
