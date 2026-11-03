#include "gen/owners.h"
class Name_250dc0 {
  public:
    int a;
    int b;
    int c;
};
class SeqEvent_250dc0 {
  public:
    SeqEvent_250dc0();
    virtual void Foo();
    char pad[4];
};
class SeqEventStopTrack : public SeqEvent_250dc0 {
  public:
    SeqEventStopTrack();
    virtual void Foo();
    int b;
    int c;
    Name_250dc0 name;
    char flag;
};
SeqEventStopTrack::SeqEventStopTrack() : SeqEvent_250dc0() {
    b = 0;
    c = 0;
    ((owners::String_23fc40 *)&name)->FUN_0023fc40("MySeqTrack", (hulk_intptr)2);
    flag = 0;
}
