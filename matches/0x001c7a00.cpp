class Sub { public: void Init(); };
class ShadowGenerator { public: int mVft; int mValue; Sub mSub; ShadowGenerator(); };
ShadowGenerator::ShadowGenerator() { mValue = 0; mVft = 0x421a68; mSub.Init(); }