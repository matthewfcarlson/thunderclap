// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 3/4, incomplete)
// FUN_0028b970 @ 0x0028b970
void __cdecl thunk_FUN_0008d340(void *);
extern void *DAT_0042c920[];
extern void *DAT_0042c930[];
struct Resource {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
};
struct SimpleChannel {
    void **vtable;
    char padding[8];
    Resource *resource;
    char padding2[4];
    void *data;
    void FUN_0028b970();
};
void SimpleChannel::FUN_0028b970() {
    vtable = DAT_0042c930;
    if (resource == 0) {
        thunk_FUN_0008d340(data);
    } else {
        resource->FUN_00000001();
        resource = 0;
    }
    data = 0;
    vtable = DAT_0042c920;
}
