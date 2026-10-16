namespace core {
class MemoryDlAllocator {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool vfunc_8(void* p);
    char pad[8];
    unsigned lo;
    unsigned hi;
};
bool MemoryDlAllocator::vfunc_8(void* p) {
    unsigned x = (unsigned)p;
    if (x < lo || x >= hi) {
        if (x == 0)
            goto yes;
        return false;
    }
yes:
    return true;
}
} // namespace core