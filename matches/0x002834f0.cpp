// Same code shape as 0x001c5640 (propagated; names are from that function)
class EffectQueue_2834f0 {
  public:
    virtual void f();
    void Cleanup1();
    void Cleanup2();
    ~EffectQueue_2834f0();
    int mData;
};
EffectQueue_2834f0::~EffectQueue_2834f0() {
    Cleanup1();
    Cleanup2();
}