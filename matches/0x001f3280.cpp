extern "C" char DAT_00424ae4[];
class CSoundSequenceVoice {
  public:
    void* vftable;
    void* member;
};
extern void __cdecl FUN_0024af00(void*);
void __fastcall FUN_001f3280(CSoundSequenceVoice* self) {
    self->vftable = (void*)((int)DAT_00424ae4);
    if (self->member) {
        FUN_0024af00(self->member);
        self->member = 0;
    }
}