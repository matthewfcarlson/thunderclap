struct IRefCount {
    virtual void a();
    virtual void Release();
};
struct CSoundSequence {
    void** vptr;
    char pad[0x18];
    IRefCount* member;
    void cleanup();
};
extern void* soundvt[];
extern void* refvt[];
void CSoundSequence::cleanup() {
    vptr = soundvt;
    if (member) {
        member->Release();
        member = 0;
    }
    vptr = refvt;
}