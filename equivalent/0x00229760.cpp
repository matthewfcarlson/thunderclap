// STATUS: equivalent (tools/equiv.py level 3: 351 inputs, branch coverage 8/8)
// FUN_00229760 @ 0x00229760
struct FUN_0022a980 {
    FUN_0022a980(unsigned int context);
    virtual void slot0();
    char padding[0x24];
};
namespace choreo2 {
struct LocomotionSteerDriver : FUN_0022a980 {
    unsigned int width;
    unsigned int count;
    unsigned int state;
    char pad34[0x89c-0x34];
    unsigned char enabled;
    unsigned char active;
    char pad89e[2];
    unsigned int a,b,c,d,e,f;
    char pad8b8[0x900-0x8b8];
    unsigned int g,h,i;
    virtual void slot0();
    void FUN_00228ac0(unsigned int index, const float* row, float weight);
    LocomotionSteerDriver(unsigned int context, unsigned int width_, unsigned int count_, const float* rows, const float* weights);
};
LocomotionSteerDriver::LocomotionSteerDriver(unsigned int context, unsigned int width_, unsigned int count_, const float* rows, const float* weights)
: FUN_0022a980(context) {
    width=width_; count=count_; state=0;
    enabled=1; active=1;
    a=0; b=0; c=0; d=0; e=0; f=0; g=0; h=0; i=0;
    if(rows) {
        unsigned int stride=width+1;
        for(unsigned int index=0; index<count; ++index) {
            float weight=-1.0f;
            if(weights) weight=weights[index];
            FUN_00228ac0(index, rows, weight);
            rows+=stride;
        }
    }
}
}
