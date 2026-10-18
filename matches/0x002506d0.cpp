extern "C" __int64 __cdecl lookup(const char*, int, int) throw();
struct Temp {
    char data[12];
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
};
struct Base {
    virtual void vf();
    Base(Temp*, const __int64&, int, int) throw();
};
struct SeqEventWaitBeatType : Base {
    SeqEventWaitBeatType();
    virtual void vf();
};
SeqEventWaitBeatType::SeqEventWaitBeatType()
    : Base(Temp().Init("Beat", 0), lookup("SeqEventWaitBeat", 0, 0), 20, 4) {}