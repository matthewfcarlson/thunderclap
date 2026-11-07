extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
struct FUN_00240060 {
    char data[12];
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
struct FUN_002605e0 {
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void foo();
};
struct SeqEventStreamType : FUN_002605e0 {
    SeqEventStreamType();
    virtual void foo();
};
SeqEventStreamType::SeqEventStreamType() : FUN_002605e0(FUN_00240060().FUN_0023fc40("Stream", 0), FUN_002672f0("SeqEventStream", 0, 0), 32, 8) {}