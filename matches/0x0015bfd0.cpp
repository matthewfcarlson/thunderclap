extern "C" char DAT_00415aa0[];
struct Sub_15bfd0 {
    char pad[8];
    void init();
};
class LocomotionSprintTrack {
  public:
    char a[0x30];
    Sub_15bfd0 s0, s1, s2, s3, s4;
    void finish();
};
void __fastcall FUN_0015bfd0(LocomotionSprintTrack* self, void*) {
    *(int*)self = ((int)DAT_00415aa0);
    self->s4.init();
    self->s3.init();
    self->s2.init();
    self->s1.init();
    self->s0.init();
    self->finish();
}