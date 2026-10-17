// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventPlayTrack::vfunc_2 @ 0x002517e0
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
extern char DAT_004e6c30;
void* __cdecl FUN_00247530(void*);
namespace audio {
struct SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void* vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct SeqActionPlayTrack { virtual void vfunc_0(); char pad[4]; SeqEvent* event; int state; };
struct SeqEventPlayTrack : SeqEvent { virtual void* vfunc_2(void*); };
}
struct TrackPlayer { void* FUN_0025dc20(audio::SeqActionPlayTrack*); };
void* audio::SeqEventPlayTrack::vfunc_2(void* player) {
    audio::SeqActionPlayTrack* action = (audio::SeqActionPlayTrack*)FUN_00247530(&DAT_004e6c30);
    if (action) {
        action = new (action) audio::SeqActionPlayTrack;
        action->event = this;
        action->state = 0;
    }
    return ((TrackPlayer*)player)->FUN_0025dc20(action);
}