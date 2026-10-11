extern "C" char DAT_0042cb5c[];
class ShaderFloatBroadcast {
  public:
    int mVft;
    int mZero;
    int mA;
    int mB;
    ShaderFloatBroadcast(int a, int b);
};
ShaderFloatBroadcast::ShaderFloatBroadcast(int a, int b) {
    mZero = 0;
    mVft = ((int)DAT_0042cb5c);
    mA = a;
    mB = b;
}