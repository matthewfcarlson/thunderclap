extern "C" char DAT_0042d1ec[];
extern "C" char DAT_0042d28c[];
extern "C" void _ReadWriteBarrier();
class Ref_296b50 {
  public:
    virtual void f();
    virtual void Release() throw();
};
class DrawableNode {
  public:
    char pad[0x18];
    Ref_296b50* member;
    void Cleanup();
    void Finish();
};
void DrawableNode::Cleanup() {
    *(void**)this = (void*)((int)DAT_0042d28c);
    _ReadWriteBarrier();
    if (member) {
        member->Release();
        member = 0;
    }
    *(void**)this = (void*)((int)DAT_0042d1ec);
    Finish();
}
