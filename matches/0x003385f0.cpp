class Inner_3385f0 {
  public:
    virtual void v0();
    virtual bool Test(int);
};
class Target_3385f0 {
  public:
    char pad[4];
    Inner_3385f0* obj;
    char pad2[0x824 - 8];
    int state;
    bool Run(int x);
};
bool Target_3385f0::Run(int x) {
    if (obj->Test(x)) {
        state = 1;
        return true;
    }
    state = 0;
    return false;
}