class Obj {
  public:
    virtual ~Obj() throw();
    char mPad[0x0c];
    int mFlag;
    char Set(int v);
};

char Obj::Set(int v) {
    mFlag = v;
    return 1;
}
