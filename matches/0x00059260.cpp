class CFightParams {
  public:
    virtual void V();
    int pad;
    int value;
    int x;
    int y;
    CFightParams* Init(int);
};
struct ThisCall_00236a60 {
    void BaseInit();
};
extern "C" int fightvftable;
CFightParams* CFightParams::Init(int v) {
    ((ThisCall_00236a60*)(this))->BaseInit();
    value = v;
    x = 0;
    y = 0;
    *(int*)this = (int)&fightvftable;
    return this;
}