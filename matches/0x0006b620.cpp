class Helper {
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
    vptr = (int*)0x3fbb34;
    ((Helper*)((char*)this + 0x60))->f();
    ((Helper*)((char*)this + 0x10))->f();
    vptr = (int*)0x3f98d0;
    BaseDtor();
    if (flag & 1)
        Final(this);
    return this;
}
