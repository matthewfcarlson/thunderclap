class Obj {
  public:
    virtual void A();
    char pad[0x30];
    int m;
    char Set(int x);
};
char Obj::Set(int x) {
    m = x;
    return 1;
}