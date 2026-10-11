extern "C" char DAT_00421a68[];
class Sub {
  public:
    void Init();
};
class ShadowGenerator {
  public:
    int mVft;
    int mValue;
    Sub mSub;
    ShadowGenerator();
};
ShadowGenerator::ShadowGenerator() {
    mValue = 0;
    mVft = ((int)DAT_00421a68);
    mSub.Init();
}