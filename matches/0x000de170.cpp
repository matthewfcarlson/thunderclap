extern "C" void _ReadWriteBarrier();
extern void* gVtable;
class ControllerPollerBase {
  public:
    virtual void Release(int);
    char pad[12];
    void* mRef;
    void Clear();
};
void ControllerPollerBase::Clear() {
    *(void**)this = &gVtable;
    _ReadWriteBarrier();
    if (mRef) {
        ((ControllerPollerBase*)mRef)->Release(1);
        mRef = 0;
    }
}