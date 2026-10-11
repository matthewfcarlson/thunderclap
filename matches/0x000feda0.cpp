extern "C" char DAT_0040d164[];
class CActorGolem {
  public:
    void* vptr;
    char pad[0xF4];
    int value;
    void init();
};
CActorGolem* __fastcall FUN_000feda0(CActorGolem* self) {
    self->init();
    self->vptr = (void*)((int)DAT_0040d164);
    self->value = 0;
    return self;
}