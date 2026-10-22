extern "C" __int64 __cdecl lookup(const char*, int, int) throw();
struct Temp {
    char data[12];
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
};
struct SeqEventType_2506d0 {
    virtual void vf();
    SeqEventType_2506d0(Temp*, const __int64&, int, int) throw();
};
struct SeqEventWaitBeatType : SeqEventType_2506d0 {
    SeqEventWaitBeatType();
    virtual void vf();
};
SeqEventWaitBeatType::SeqEventWaitBeatType()
    : SeqEventType_2506d0(Temp().Init("Beat", 0), lookup("SeqEventWaitBeat", 0, 0), 20, 4) {}