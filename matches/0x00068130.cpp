class Obj_68130 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int x);
};

char Obj_68130::Set(int x) {
    mValue = x;
    return 1;
}
