class Track {
public:
    virtual void v0();
    ~Track();
};

struct P18 { ~P18(); char pad[0x20]; };
struct P38 { ~P38(); char pad[0x50]; };
struct P88 { ~P88(); char pad[0x14]; };
struct P9c { ~P9c(); char pad[0xc]; };
struct Pa8 { ~Pa8(); char pad[4]; };

extern int g_FireProjectileTrackVtable;
void FUN_00267090(void *);

class FireProjectileTrack : public Track {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual FireProjectileTrack *vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
private:
    char pad0[0x18 - 4];
    P18 m18;
    P38 m38;
    P88 m88;
    P9c m9c;
    Pa8 ma8;
};

FireProjectileTrack *FireProjectileTrack::vfunc_5(unsigned char flag) {
    *(int *)this = (int)&g_FireProjectileTrackVtable;
    ma8.~Pa8();
    m9c.~P9c();
    m88.~P88();
    m38.~P38();
    m18.~P18();
    this->Track::~Track();
    if ((flag & 1) != 0) FUN_00267090(this);
    return this;
}
