extern "C" void _ReadWriteBarrier();
namespace core {
class IRefCount {
  public:
    virtual void tick(int);
    int filler;
    int count;
    inline void step() {
        if (--count == 0) {
            count = 1500;
            _ReadWriteBarrier();
            tick(1);
        }
    }
};
class DebugConsole {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    IRefCount ref;
};
void DebugConsole::vfunc_1() {
    ref.step();
}
} // namespace core