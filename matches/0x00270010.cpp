namespace core {
class IMemoryPool {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class IMemoryAllocator {
  public:
    virtual void vfunc_2();
};
class MemoryPool : public IMemoryPool, public IMemoryAllocator {
  public:
    virtual void vfunc_2();
};
extern void work(MemoryPool*);
void MemoryPool::vfunc_2() {
    work(this);
}
MemoryPool instance;
} // namespace core