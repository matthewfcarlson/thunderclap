typedef unsigned char byte_296e00;
struct Visitor_296e00 {
    virtual void v0();
    virtual void v1();
};
namespace pure3d {
namespace scenegraph {
struct ShaderCallbackVisitor : Visitor_296e00 {
    void* mThing;
    virtual void vfunc_0();
    virtual ShaderCallbackVisitor* vfunc_1(byte_296e00);
};
extern void* shaderVtable;
void thunk_FUN_00267090(ShaderCallbackVisitor*);
ShaderCallbackVisitor* ShaderCallbackVisitor::vfunc_1(byte_296e00 param) {
    *(void**)this = &shaderVtable;
    if (mThing)
        ((Visitor_296e00*)mThing)->v1();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace scenegraph
} // namespace pure3d