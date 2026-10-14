typedef unsigned char byte_296e00;
struct VisitorBase {
    virtual void v0();
    virtual void v1();
};
namespace pure3d {
namespace scenegraph {
struct ShaderCallbackVisitor : VisitorBase {
    void* mThing;
    virtual void vfunc_0();
    virtual ShaderCallbackVisitor* vfunc_1(byte_296e00);
};
extern void* shaderVtable;
void thunk_FUN_00267090(ShaderCallbackVisitor*);
ShaderCallbackVisitor* ShaderCallbackVisitor::vfunc_1(byte_296e00 param) {
    *(void**)this = &shaderVtable;
    if (mThing)
        ((VisitorBase*)mThing)->v1();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace scenegraph
} // namespace pure3d