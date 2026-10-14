// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062360 @ 0x00062360
struct Name {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) TrackBase {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    TrackBase() { FUN_00236d40(); }
};

class CSmartPropUpdateAttachmentTrack : public TrackBase {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c, f10, f14;
    Name bone;
    Name prop;
    char enabled;
    char pad29[3];
    int f2c, f30, f34, f38, f3c, f40, f44;

    CSmartPropUpdateAttachmentTrack();
};

CSmartPropUpdateAttachmentTrack::CSmartPropUpdateAttachmentTrack() {
    f0c = 0; f10 = 0; f14 = 0;
    bone.FUN_0027af00();
    prop.FUN_0027af00();
    enabled = 1;
    f2c = 0; f30 = 0; f34 = 0; f38 = 0; f3c = 0; f40 = 0; f44 = 0;
    bone.FUN_0027b040("Wrist_R");
    prop.FUN_0027b040("Wealded_Weap_1");
}
