namespace core {
class MemoryDlAllocator {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(unsigned int);
    unsigned char pad[8];
    unsigned int lo, hi;
};
bool MemoryDlAllocator::vfunc_5(unsigned int p) {
    if (p >= lo && p < hi || p == 0)
        return true;
    return false;
}
} // namespace core