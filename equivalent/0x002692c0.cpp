// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002692c0 @ 0x002692c0
namespace XAPILIB { int __stdcall XInputGetState(unsigned int, void *); }
extern unsigned int DAT_0042b2f0, DAT_0042b2f4, DAT_0042b2f8;
extern char DAT_0042b2e4[], DAT_0042b2d8[];
struct Triple { unsigned int a,b,c; };
extern Triple DAT_004cd6a8[20];
struct Input {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(void *);
};
struct Entry { Input input; char padding[0x1c]; Triple values; char rest[8]; };
struct Device {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(unsigned int);
    virtual void f19(); virtual void f20(unsigned int,unsigned int);
    unsigned int unknown4;
    unsigned int handle;
    unsigned int slot;
    unsigned int port;
    unsigned int count;
    Entry entries[20];
    char pad[0x430 - 0x18 - 20*0x34];
    char *leftName;
    char pad2[12];
    char *rightName;
    char pad3[4];
    unsigned int name0,name1,name2;
    unsigned int other;
    unsigned char zeros[0x46];
    unsigned char active;
    void FUN_002692c0(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int e,unsigned int f,unsigned int g);
};
void Device::FUN_002692c0(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int e,unsigned int f,unsigned int g)
{
    handle=a; slot=b; port=c; count=0;
    active=0;
    for(int i=0;i<0x46;i++) zeros[i]=0;
    other=g;
    name0=DAT_0042b2f0; name1=DAT_0042b2f4; name2=DAT_0042b2f8;
    ((unsigned char*)&name2)[2]=(unsigned char)(c+0x30);
    ((unsigned char*)&name1)[0]=(unsigned char)(b+0x30);
    count=20;
    for(unsigned int j=0;j<count;j++) {
        entries[j].values=DAT_004cd6a8[j];
        if(handle) {
            unsigned char state[22];
            for(int k=0;k<22;k++) state[k]=0;
            XAPILIB::XInputGetState(handle,state);
            entries[j].input.f12(state+4);
        }
    }
    leftName=DAT_0042b2e4;
    rightName=DAT_0042b2d8;
    active=1;
    f20(e,f);
    f18(d);
}