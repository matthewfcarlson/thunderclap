class CFightParams {
  public:
    virtual void V();
    int pad;
    int value;
    int x;
    int y;
    CFightParams* Init(int);
};
extern "C" void BaseInit();
extern "C" int fightvftable;
CFightParams* CFightParams::Init(int v) {
    BaseInit();
    value = v;
    x = 0;
    y = 0;
    *(int*)this = (int)&fightvftable;
    return this;
}