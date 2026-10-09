// Same code shape as 0x001c5640 (propagated; names are from that function)
class Store {
  public:
    virtual void f();
    void Cleanup1();
    void Cleanup2();
    ~Store();
    int mData;
};
Store::~Store() {
    Cleanup1();
    Cleanup2();
}