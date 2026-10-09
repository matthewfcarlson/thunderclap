class pddiExtVisibilityTest {
  public:
    virtual void vfunc_0();
    virtual unsigned int vfunc_1();
};
class pddiExtension {};
class d3dExtVisibilityTest : public pddiExtVisibilityTest, public pddiExtension {
  public:
    virtual void vfunc_0();
    virtual unsigned int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
unsigned int d3dExtVisibilityTest::vfunc_1() {
    return 0x4000;
}