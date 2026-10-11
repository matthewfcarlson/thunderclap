extern "C" char DAT_0042d1ec[];
extern "C" char DAT_0042d28c[];
extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void f();
    virtual void Release() throw();
};
class DrawableNode {
  public:
    char pad[0x18];
    Ref* member;
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
