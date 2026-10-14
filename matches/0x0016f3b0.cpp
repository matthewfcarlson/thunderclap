class Obj_16f3b0 {
    char pad[12];

  public:
    int mValue;
    char Set(int x);
};
char Obj_16f3b0::Set(int x) {
    mValue = x;
    return 1;
}