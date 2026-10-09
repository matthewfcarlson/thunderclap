extern "C" void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
extern int gStateA;
extern int gStateB;
extern int gStateC;
extern int gValues[128];
class Obj {
  public:
    char pad0[0x5c];
    unsigned char mEnabled;
    int mMode;
    char pad1[0x10c - 0x64];
    int mValue;
    void Set(unsigned char enabled, int mode, int value);
};
void Obj::Set(unsigned char enabled, int mode, int value) {
    if (mEnabled != enabled) {
        mEnabled = enabled;
        D3DDevice_SetRenderState_Simple(0x40300, (unsigned char)enabled);
        gStateA = (unsigned char)enabled;
    }
    if (mEnabled != 0) {
        if (mMode != mode) {
            mMode = mode;
            int v = gValues[mode];
            D3DDevice_SetRenderState_Simple(0x4033c, v);
            gStateB = v;
        }
        if (mEnabled != 0 && mValue != value) {
            mValue = value;
            D3DDevice_SetRenderState_Simple(0x40340, value);
            gStateC = value;
        }
    }
}