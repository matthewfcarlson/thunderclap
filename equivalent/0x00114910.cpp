// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_5 @ 0x00114910
void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace hulkfight { namespace ai {
struct TokenSupressTrack {
    virtual void vfunc_0();
    char pad4[4];
    int count;
    int valueC;
    float value10;
    unsigned char active;
    char pad15[3];
    float value18;
    unsigned char flag1c;
    unsigned char flag1d;
    char pad1e[2];
    void FUN_00236d40();
};
}}
namespace fight {
struct TrackFactoryTemplate {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual hulkfight::ai::TokenSupressTrack* vfunc_5();
};
}
hulkfight::ai::TokenSupressTrack* fight::TrackFactoryTemplate::vfunc_5() {
    hulkfight::ai::TokenSupressTrack* track = (hulkfight::ai::TokenSupressTrack*)FUN_0008d690(0x20);
    if (track) {
        track->FUN_00236d40();
        new(track) hulkfight::ai::TokenSupressTrack;
        track->active = 1;
        track->count = 1;
        track->valueC = 0;
        track->value10 = -1.0f;
        track->value18 = -1.0f;
        track->flag1c = 0;
        track->flag1d = 0;
    }
    return track;
}