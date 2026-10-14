// STATUS: equivalent (tools/equiv.py level 3: 375 inputs, branch coverage 8/8)
// FUN_00227590 @ 0x00227590
struct FUN_0022a980 {
    virtual void slot0();
    FUN_0022a980(void*);
    char padding[0x24];
};
namespace choreo2 {
struct LocomotionStrafeDriver : FUN_0022a980 {
    virtual void slot0();
    unsigned width;
    unsigned count;
    unsigned zero30;
    char pad34[0x12dc-0x34];
    unsigned char flagA,flagB;
    char padDE[2];
    unsigned zeroE0,zeroE4,zeroE8,zeroEC;
    char padF0[0x1320-0x12f0];
    unsigned zero20,zero24,zero28;
    void FUN_00226610(unsigned, const unsigned*, const unsigned*);
    LocomotionStrafeDriver(void*,unsigned,unsigned,const unsigned*,const unsigned*);
};
LocomotionStrafeDriver::LocomotionStrafeDriver(void* context,unsigned w,unsigned n,const unsigned* data,const unsigned* other) : FUN_0022a980(context) {
    flagA=1; flagB=1;
    width=w; count=n; zero30=0;
    zeroE0=0; zeroE4=0; zeroE8=0; zeroEC=0;
    zero20=0; zero24=0; zero28=0;
    if(data) {
        unsigned strideOther=other!=0;
        for(unsigned i=0;i<count;++i) {
            unsigned offset=width*i;
            FUN_00226610(i,data+offset,other+offset*strideOther);
        }
    }
}
}
