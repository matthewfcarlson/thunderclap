extern "C" char DAT_0042e5e4[];
class B_2b55b0 {
  public:
    char p[0x10];
    int x;
    B_2b55b0();
};
class ShadowSkinImpl : public B_2b55b0 {
  public:
    char q[0x70 - 0x14];
    int a, b, c, d;
    ShadowSkinImpl();
};
ShadowSkinImpl::ShadowSkinImpl() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    *(int*)this = ((int)DAT_0042e5e4);
    *(int*)((char*)this + 0x10) = 2;
}