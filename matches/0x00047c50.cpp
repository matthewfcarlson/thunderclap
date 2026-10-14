class Obj_47c50 {
  public:
    virtual ~Obj_47c50() throw();
    char mPad[0x0c];
    int mFlag;
    char Set(int v);
};

char Obj_47c50::Set(int v) {
    mFlag = v;
    return 1;
}
