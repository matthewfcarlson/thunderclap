#include "compat/ptr.h"
#include "gen/audio.h"
extern "C" char DAT_00429dcc[];
struct SeqEventPlayTrack_nv_2513d0 {
    void Init();
};
class Track_2513d0 {
  public:
    void Setup(const char*, int);
};
class SeqEventPlayTrack_2513d0 {
  public:
    int vptr;
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
    self->track.Setup("MySeqTrack", 2);
    return self;
}