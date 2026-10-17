// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 3/4, incomplete)
// pure3d::SimpleChannel::vfunc_1 @ 0x0028b490
namespace pure3d {
struct Object {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Channel {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    char pad[8];
    Object* object;
    char pad2[4];
    void* data;
};
struct SimpleChannel : Channel {
    void vfunc_1();
};
}
void __cdecl FUN_0008d340(void*);
void pure3d::SimpleChannel::vfunc_1() {
    if (object == 0) {
        FUN_0008d340(data);
        data = 0;
        return;
    }
    if (object != 0) {
        object->vfunc_1();
        object = 0;
    }
    data = 0;
}
