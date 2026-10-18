extern "C" __int64 __cdecl MakeId(const char*, int, int) throw();
struct Temp {
    char data[12];
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
};
struct Base {
    Base(Temp*, const __int64&, int, int) throw();
    virtual void foo();
};
struct SeqEventStreamType : Base {
    SeqEventStreamType();
    virtual void foo();
};
SeqEventStreamType::SeqEventStreamType() : Base(Temp().Init("Stream", 0), MakeId("SeqEventStream", 0, 0), 32, 8) {}