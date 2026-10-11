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
    *(void**)this = (void*)0x42d28c;
    _ReadWriteBarrier();
    if (member) {
        member->Release();
        member = 0;
    }
    *(void**)this = (void*)0x42d1ec;
    Finish();
}
