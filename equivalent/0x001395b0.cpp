// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// fight::TrackFactoryTemplate<hulkfight::motion::FlyingBrakeTrack>::vfunc_5 @ 0x001395b0
typedef unsigned int size_t;
void* __cdecl FUN_0008d690(size_t);
struct Track_1395b0 {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    char gap[8];
    void FUN_00236d40();
};
struct FlyingBrakeTrack : Track_1395b0 {
    float field0c, field10, field14, field18, field1c, field20;
    int field24, field28, field2c;
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
};
struct TrackFactoryTemplate {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual FlyingBrakeTrack* vfunc_5();
};
inline void* operator new(size_t, void* p) throw() { return p; }
FlyingBrakeTrack* TrackFactoryTemplate::vfunc_5() {
    void* storage = FUN_0008d690(0x30);
    if (!storage) return 0;
    FlyingBrakeTrack* track = (FlyingBrakeTrack*)storage;
    track->FUN_00236d40();
    track = new (storage) FlyingBrakeTrack;
    track->field0c = 0;
    track->field10 = -1.0f;
    track->field14 = 50.0f;
    track->field18 = 10.0f;
    track->field1c = 50.0f;
    track->field20 = -1.0f;
    track->field24 = -5;
    track->field28 = 0;
    track->field2c = 0;
    return track;
}