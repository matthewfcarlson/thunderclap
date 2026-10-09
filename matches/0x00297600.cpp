class Ref { public: virtual void f0(); virtual void f1(); };
class TransformNode {
public:
    virtual void f0();
    virtual void f1();
    TransformNode* vfunc_2(unsigned int p);
    void helper();
    char pad[0xA8 - 4];
    Ref* ref;
};
void __cdecl thunk_FUN_00267090(TransformNode*);
TransformNode* TransformNode::vfunc_2(unsigned int p) {
    *(volatile int*)this = 0x42d3bc;
    Ref* r = *(Ref* volatile*)&ref;
    if (r) { r->f1(); ref = 0; }
    helper();
    if (p & 1) thunk_FUN_00267090(this);
    return this;
}
