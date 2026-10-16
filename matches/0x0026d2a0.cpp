namespace core {
class Primary {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Secondary {
  public:
    virtual void vfunc_2();
};
class __declspec(dllexport) MemoryTwoWayAllocator : public Primary, public Secondary {
  public:
    virtual void vfunc_2();
};
void MemoryTwoWayAllocator::vfunc_2() {
    extern void action();
    action();
}
} // namespace core