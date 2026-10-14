class Obj_123990 {
  public:
    char pad[0xc];
    int mValue;
    char Set(int x);
};

char Obj_123990::Set(int x) {
    mValue = x;
    return 1;
}