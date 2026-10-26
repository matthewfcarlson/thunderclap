#include "decls/data/engine/audio.h"
// data: playName = DAT_00429df8, trackName = DAT_00429e00

typedef unsigned long long U64;
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
SeqEventPlayTrackType::SeqEventPlayTrackType() : SeqEventType_251510(Temp().Init(DAT_00429df8, 0), MakeId(DAT_00429e00, 0, 0), 32, 4) {}