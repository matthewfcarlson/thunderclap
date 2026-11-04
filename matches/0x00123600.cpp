class Obj_123600 {
  public:
    virtual void v();
    char pad[8];
    int mVal;
    char SetCompare_00123600(int x);
};

char Obj_123600::SetCompare_00123600(int x) {
    mVal = x;
    return 1;
}
