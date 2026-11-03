#include "compat/ptr.h"
#include "gen/audio.h"
#include "gen/owners.h"
extern "C" char DAT_00429dcc[];
struct SeqEventPlayTrack_nv_2513d0 {
    void Init();
};
class Track_2513d0 {
  public:
};
class SeqEventPlayTrack_2513d0 {
  public:
    hulk_intptr vptr;
    char pad4[4];
    int a;
    int b;
    unsigned char c;
    char pad11[3];
    Track_2513d0 track;
};
SeqEventPlayTrack_2513d0* __fastcall Target(SeqEventPlayTrack_2513d0* self) {
    ((SeqEventPlayTrack_nv_2513d0*)(((audio::SeqEventPlayTrack*)self)))->Init();
    self->vptr = ((hulk_intptr)DAT_00429dcc);
    self->a = 0;
    self->b = 0;
    self->c = 0;
    ((owners::String_23fc40 *)&(self->track))->FUN_0023fc40("MySeqTrack", (hulk_intptr)2);
    return self;
}