extern "C" char DAT_004298fc[];
extern "C" char DAT_004e6c30[];
extern void __cdecl Cleanup(void*, void*);
class SeqActionPlayTrack {
  public:
    int* vptr;
    SeqActionPlayTrack* vfunc_0(int);
};
SeqActionPlayTrack* SeqActionPlayTrack::vfunc_0(int x) {
    SeqActionPlayTrack* self = this;
    vptr = (int*)((int)DAT_004298fc);
    if (x & 1)
        Cleanup((void*)((int)DAT_004e6c30), self);
    return self;
}