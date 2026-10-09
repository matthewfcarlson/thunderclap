struct SeqEventStopTrack {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[12];
    SeqEventStopTrack* f4_impl(unsigned char);
};
struct H1 {
    void run();
};
struct H2 {
    void run();
};
extern void __cdecl FUN_00247550(void*, SeqEventStopTrack*);
extern char DAT_004e6bc8;
SeqEventStopTrack* SeqEventStopTrack::f4_impl(unsigned char param_2) {
    ((H1*)((char*)this + 0x10))->run();
    ((H2*)this)->run();
    if (param_2 & 1)
        FUN_00247550(&DAT_004e6bc8, this);
    return this;
}