// STATUS: equivalent (tools/equiv.py level 3: 2886 inputs, branch coverage 2/2)
// audio::SeqTrack::vfunc_0 @ 0x002621e0
namespace audio {
struct Entry { char padding[0x24]; unsigned int count; };
struct SeqTrack {
    virtual bool vfunc_0(Entry **entry);
    virtual void vfunc_1();
};
}
unsigned char __cdecl FUN_00246f50(audio::Entry *, const char *, ...);
bool audio::SeqTrack::vfunc_0(Entry **entry) {
    if (FUN_00246f50(*entry, "[\n")) {
        ++(*entry)->count;
        FUN_00246f50(*entry, "%s ", "mName");
    }
    return false;
}