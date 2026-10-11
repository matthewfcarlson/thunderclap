extern "C" char DAT_0040f4a0[];
struct Track {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
struct PathFormationTrack : Track {
    char pad[0x30];
    void* member;
    void helper();
    virtual PathFormationTrack* vfunc_5(unsigned char);
};
void thunk_FUN_00267090(void*);
void other_free(void*);
PathFormationTrack* PathFormationTrack::vfunc_5(unsigned char flag) {
    *(void**)this = (void*)((int)DAT_0040f4a0);
    thunk_FUN_00267090(member);
    helper();
    if (flag & 1)
        other_free(this);
    return this;
}
