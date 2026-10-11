extern "C" void _ReadWriteBarrier();
class IRefCount {
  public:
    virtual void A();
    virtual void Release();
};
class DisplayTraversal {
  public:
    volatile int* vptr;
    char pad[16];
    IRefCount* mRef;
    void Fn();
};
void DisplayTraversal::Fn() {
    vptr = (volatile int*)0x42ef74;
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    vptr = (volatile int*)0x3f6098;
}