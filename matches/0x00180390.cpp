class T_180390 {
  public:
    virtual void V();
    char Set(int x);
    char pad[8];
    int mC;
};

char T_180390::Set(int x) {
    mC = x;
    return 1;
}
