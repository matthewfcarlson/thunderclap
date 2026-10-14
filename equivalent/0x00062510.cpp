// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062510 @ 0x00062510
struct Name_62510 {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) TrackBase_62510 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    TrackBase_62510() { FUN_00236d40(); }
};

class CSmartPropSpawnTrack : public TrackBase_62510 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c;
    char f10;
    char pad11[0x7f];
    int f90;
    int pad94;
    Name_62510 bone;
    Name_62510 prop;
    char enabled;
    char pada9[3];
    int fac, fb0, fb4, fb8, fbc, fc0, fc4;
    Name_62510 extra;

    CSmartPropSpawnTrack();
};

CSmartPropSpawnTrack::CSmartPropSpawnTrack() {
    f0c = 0;
    f90 = 0;
    bone.FUN_0027af00();
    prop.FUN_0027af00();
    enabled = 1;
    fac = 0; fb0 = 0; fb4 = 0; fb8 = 0; fbc = 0; fc0 = 0; fc4 = 0;
    extra.FUN_0027af00();
    bone.FUN_0027b040("Wrist_R");
    prop.FUN_0027b040("Wealded_Weap_1");
    f10 = 0;
}
