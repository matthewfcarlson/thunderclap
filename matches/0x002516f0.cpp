extern void __cdecl Cleanup(void*, void*);
class SeqActionPlayTrack {
  public:
    int* vptr;
    SeqActionPlayTrack* vfunc_0(int);
};
SeqActionPlayTrack* SeqActionPlayTrack::vfunc_0(int x) {
    SeqActionPlayTrack* self = this;
    vptr = (int*)0x4298fc;
    if (x & 1)
        Cleanup((void*)0x4e6c30, self);
    return self;
}