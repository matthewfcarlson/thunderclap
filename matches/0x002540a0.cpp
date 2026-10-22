extern "C" __int64 __cdecl MakeId(const char*, int, int) throw();
struct Temp {
    char data[12];
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
};
struct SeqEventType_2540a0 {
    SeqEventType_2540a0(Temp*, const __int64&, int, int) throw();
    virtual void foo();
};
struct SeqEventStreamType : SeqEventType_2540a0 {
    SeqEventStreamType();
    virtual void foo();
};
SeqEventStreamType::SeqEventStreamType() : SeqEventType_2540a0(Temp().Init("Stream", 0), MakeId("SeqEventStream", 0, 0), 32, 8) {}