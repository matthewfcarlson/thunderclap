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