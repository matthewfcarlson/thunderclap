class T_180390 {
  public:
    virtual void V();
    char SetTimeBegin_00180390(int x);
    char pad[8];
    int mC;
};

char T_180390::SetTimeBegin_00180390(int x) {
    mC = x;
    return 1;
}
