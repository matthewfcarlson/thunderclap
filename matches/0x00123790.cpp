class Obj_123790 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int x);
};
char Obj_123790::Set(int x) {
    mValue = x;
    return 1;
}
