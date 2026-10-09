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
    mVft = 0x42cb5c;
    mA = a;
    mB = b;
}