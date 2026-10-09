typedef unsigned int u32;
struct Helper { void f(); };
struct CEffectTrack {
    u32 *vft;
    char pad04[0x14];
    char s18[0x10];
    char s28[8];
    char s30[4];
    void Init();
};
extern u32 CEffectTrack_vftable[];
extern Helper h;
void CEffectTrack::Init() {
    vft = CEffectTrack_vftable;
    ((Helper*)s30)->f();
    ((Helper*)s28)->f();
    ((Helper*)s18)->f();
    ((Helper*)this)->f();
}