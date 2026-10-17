// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// audio::SeqActionWaitBeat::vfunc_6 @ 0x00250560
namespace audio {
struct BeatSource { char pad[0x2c]; int beat; };
struct SeqActionWaitBeat {
    void *vptr;
    char pad04[4];
    char *sequence;
    int state;
    int previousBeat;
    BeatSource *source;
    void vfunc_6(int unused);
};
}
extern "C" char __cdecl FUN_00261f90(char *sequence, int previousBeat, int currentBeat);
void audio::SeqActionWaitBeat::vfunc_6(int unused) {
    if (state == 3) {
        if (!source) {
            state = 0;
            return;
        }
        int beat = source->beat;
        if (FUN_00261f90(sequence + 8, previousBeat, beat))
            state = 0;
        previousBeat = beat;
    }
}