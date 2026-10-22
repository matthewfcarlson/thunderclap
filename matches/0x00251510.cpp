typedef unsigned long long U64;
extern const char trackName[];
extern const char playName[];
extern U64 __cdecl MakeId(const char*, int, int) throw();
class Temp {
  public:
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
    char pad[12];
};
class SeqEventType_251510 {
  public:
    SeqEventType_251510(Temp*, const U64&, int, int) throw();
    virtual void v0();
};
class SeqEventPlayTrackType : public SeqEventType_251510 {
  public:
    SeqEventPlayTrackType();
    virtual void v0();
};
SeqEventPlayTrackType::SeqEventPlayTrackType() : SeqEventType_251510(Temp().Init(playName, 0), MakeId(trackName, 0, 0), 32, 4) {}