class Obj {
  public:
    virtual void v();
    char pad[8];
    int mVal;
    char Set(int x);
};

char Obj::Set(int x) {
    mVal = x;
    return 1;
}
