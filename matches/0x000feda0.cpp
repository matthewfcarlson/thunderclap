extern "C" char DAT_0040d164[];
class CCharacterGolem_feda0 {
  public:
    void* vptr;
    char pad[0xF4];
    int value;
    void init();
};
CCharacterGolem_feda0* __fastcall FUN_000feda0(CCharacterGolem_feda0* self) {
    self->init();
    self->vptr = (void*)((int)DAT_0040d164);
    self->value = 0;
    return self;
}