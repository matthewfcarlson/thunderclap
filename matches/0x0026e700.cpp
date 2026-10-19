namespace core {
struct IDebugConsole {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned);
};
struct IRefCount {
    virtual void vfunc_2(unsigned);
};
struct DebugConsole : IDebugConsole, IRefCount {
    virtual void vfunc_2(unsigned);
};
extern void work(unsigned);
void DebugConsole::vfunc_2(unsigned flags) {
    work(flags);
}
DebugConsole instance;
} // namespace core