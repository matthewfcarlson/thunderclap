// Same code shape as 0x001c5640 (propagated; names are from that function)
class ProceduralVertexAnimController_2a6910 {
  public:
    virtual void f();
    void Cleanup1();
    void Cleanup2();
    ~ProceduralVertexAnimController_2a6910();
    int mData;
};
ProceduralVertexAnimController_2a6910::~ProceduralVertexAnimController_2a6910() {
    Cleanup1();
    Cleanup2();
}