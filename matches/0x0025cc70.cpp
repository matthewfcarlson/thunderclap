extern "C" char DAT_0042a850[];
extern "C" char DAT_004e7808[];
struct Inner {
    void Setup();
};
void Register(void*, void*);
class OmHalStream {
  public:
    int vf;
    char pad[0x1b8];
    Inner inner;
    OmHalStream* Init(unsigned char flag);
};
OmHalStream* OmHalStream::Init(unsigned char flag) {
    vf = ((int)DAT_0042a850);
    inner.Setup();
    if (flag & 1)
        Register((void*)((int)DAT_004e7808), this);
    return this;
}
