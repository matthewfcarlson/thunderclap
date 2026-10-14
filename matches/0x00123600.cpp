class Obj_123600 {
  public:
    virtual void v();
    char pad[8];
    int mVal;
    char Set(int x);
};

char Obj_123600::Set(int x) {
    mVal = x;
    return 1;
}
