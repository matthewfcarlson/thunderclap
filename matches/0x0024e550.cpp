#include "gen/owners.h"
struct Inner_24e550 {
};
class SeqEvent_24e550 {
  public:
    SeqEvent_24e550();
    virtual void g();
};
class SeqEventNestTrack_24e550 : public SeqEvent_24e550 {
  public:
    SeqEventNestTrack_24e550();
    virtual void g();
    char pad[4];
    Inner_24e550 in;
};
SeqEventNestTrack_24e550::SeqEventNestTrack_24e550() {
    ((owners::String_23fc40 *)&in)->FUN_0023fc40("MySeqTrack", (hulk_intptr)2);
}
