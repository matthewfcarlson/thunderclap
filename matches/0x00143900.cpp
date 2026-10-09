extern int WorldDamageTrack_vftable;
class Inner {
  public:
    void Init();
};
class WorldDamageTrack {
  public:
    int* vptr;
    char pad[12];
    Inner inner;
    void BaseFn();
    void Fn();
};
void WorldDamageTrack::Fn() {
    vptr = &WorldDamageTrack_vftable;
    inner.Init();
    BaseFn();
}