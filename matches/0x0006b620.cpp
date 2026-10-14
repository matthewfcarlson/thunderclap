extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fbb34[];
class Helper_6b620 {
  public:
    void f();
};
class CKeyPoseTrack {
  public:
    int* vptr;
    char pad[0x5c];
    CKeyPoseTrack* vfunc_5(unsigned char flag);
    void BaseDtor();
};
void Final(CKeyPoseTrack*);
CKeyPoseTrack* CKeyPoseTrack::vfunc_5(unsigned char flag) {
    vptr = (int*)((int)DAT_003fbb34);
    ((Helper_6b620*)((char*)this + 0x60))->f();
    ((Helper_6b620*)((char*)this + 0x10))->f();
    vptr = (int*)((int)DAT_003f98d0);
    BaseDtor();
    if (flag & 1)
        Final(this);
    return this;
}
