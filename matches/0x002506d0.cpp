extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
struct FUN_00240060 {
    char data[12];
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
struct FUN_002605e0 {
    virtual void vf();
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
};
struct SeqEventWaitBeatType : FUN_002605e0 {
    SeqEventWaitBeatType();
    virtual void vf();
};
SeqEventWaitBeatType::SeqEventWaitBeatType()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("Beat", 0), FUN_002672f0("SeqEventWaitBeat", 0, 0), 20, 4) {}