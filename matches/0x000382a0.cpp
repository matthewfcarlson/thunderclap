namespace core {
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    unsigned int count;
};
} // namespace core
namespace content {
class LoadObject : public core::IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
};
void LoadObject::vfunc_1() {
    if (count < 2) {
        volatile unsigned int* q = &count;
        *q = 0x8000000;
        vfunc_2(1);
        return;
    }
    --count;
}
} // namespace content