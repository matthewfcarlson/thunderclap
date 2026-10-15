extern "C" __int64 __cdecl MakeId(const char*, int, int) throw();
struct Temp {
    char data[12];
    Temp(const char*, int, const __int64&, int, int) throw();
    ~Temp() throw();
};
struct Base {
    Base(const Temp&) throw();
    virtual void foo();
};
struct SeqEventStreamType : Base {
    SeqEventStreamType();
    virtual void foo();
};
SeqEventStreamType::SeqEventStreamType() : Base(Temp("Stream", 0, MakeId("SeqEventStream", 0, 0), 32, 8)) {}