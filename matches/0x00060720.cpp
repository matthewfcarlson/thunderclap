extern "C" char DAT_003faa80[];
typedef unsigned int u32;
struct Helper {
    void Init();
};
struct CEffectTrack {
    u32 vft;
    char pad[0x30 - 4];
    void Finish();
};
void __fastcall FUN_00060720(CEffectTrack* self) {
    self->vft = ((int)DAT_003faa80);
    ((Helper*)((char*)self + 0x30))->Init();
    ((Helper*)((char*)self + 0x28))->Init();
    ((Helper*)((char*)self + 0x18))->Init();
    self->Finish();
}
