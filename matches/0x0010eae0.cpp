extern "C" char DAT_0040dc14[];
class HulkActionTrack {
  public:
    unsigned int vf;
    char pad[0x14];
    HulkActionTrack* vfunc_5(unsigned int);
};
class Sub {
  public:
    void Destroy();
};
class Base {
  public:
    void Destroy();
};
extern void __cdecl thunk_FUN_00267090(HulkActionTrack*);
HulkActionTrack* HulkActionTrack::vfunc_5(unsigned int flags) {
    vf = ((int)DAT_0040dc14);
    ((Sub*)((char*)this + 0x18))->Destroy();
    ((Base*)this)->Destroy();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}