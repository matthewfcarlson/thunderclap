class FaceTargetTrack {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int pad;
    int m8;
    int mc;
    float m10;
    FaceTargetTrack();
};
class TrackFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual FaceTargetTrack* V5();
};
extern void* __cdecl Allocate(unsigned int);
extern int FaceVtable;
FaceTargetTrack* TrackFactoryTemplate::V5() {
    FaceTargetTrack* p = (FaceTargetTrack*)Allocate(0x14);
    if (p) {
        p->FaceTargetTrack::FaceTargetTrack();
        *(int*)p = (int)&FaceVtable;
        p->mc = 0;
        p->m10 = -1.0f;
        p->m8 = 1;
        return p;
    }
    return 0;
}