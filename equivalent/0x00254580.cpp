// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventStream::vfunc_2 @ 0x00254580
#include "decls/data/engine/audio.h"

void* __cdecl FUN_00247530(void*);
namespace audio {
struct SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct SeqEventStream : SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); };
struct SeqActionStream {
 virtual void vfunc_0();
 char reserved[4];
 SeqEventStream* stream;
 int first;
 int second;
 int field14;
 char reserved18[4];
 int field1c;
 int field20;
 int field24;
 int field28;
};
}
struct ActionTarget { void FUN_0025dc20(audio::SeqActionStream*); };
void audio::SeqEventStream::vfunc_2(void* target) {
 audio::SeqActionStream* action = (audio::SeqActionStream*)FUN_00247530(((char*)((char*)&DAT_004e7200 + 104)));
 if (action) {
  action->audio::SeqActionStream::SeqActionStream();
  action->field14 = 0;
  action->field1c = 0;
  action->field20 = 0;
  action->field28 = 0;
  action->stream = this;
  action->first = -1;
  action->second = -1;
  action->field24 = 0;
 }
 ((ActionTarget*)target)->FUN_0025dc20(action);
}