extern "C" void _ReadWriteBarrier();
extern void* gVtable_de170;
class ControllerPollerBase {
  public:
    virtual void Release(int);
    char pad[12];
    void* mRef;
    void Clear();
};
void ControllerPollerBase::Clear() {
    *(void**)this = &gVtable_de170;
    _ReadWriteBarrier();
    if (mRef) {
        ((ControllerPollerBase*)mRef)->Release(1);
        mRef = 0;
    }
}