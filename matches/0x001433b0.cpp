class Obj_1433b0 {
  public:
    virtual void A();
    char pad[0x30];
    int m;
    char Set(int x);
};
char Obj_1433b0::Set(int x) {
    m = x;
    return 1;
}