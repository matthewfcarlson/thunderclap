// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001047b0 @ 0x001047b0
struct Resource_1047b0 { virtual void retain(); };
struct Arg_1047b0 { Resource_1047b0* FUN_000fefa0(); };
struct FUN_000fc760 {
    FUN_000fc760(Arg_1047b0*);
    virtual void baseVirtual();
    char pad[0x58];
};
struct Obj_1047b0 { virtual void retain(); Obj_1047b0* FUN_00109ba0(); };
extern "C" void* __cdecl FUN_0008d690(unsigned);
struct CPathAgent : FUN_000fc760 {
    unsigned f5c;
    Resource_1047b0* f60;
    unsigned f64,f68,f6c,f70,f74,f78;
    char pad7c[12];
    unsigned char f88,f89; char pad8a[2];
    float f8c; unsigned char f90,f91; char pad92[2];
    float f94,f98; unsigned f9c; char pada0[28];
    unsigned fbc,fc0,fc4; Obj_1047b0* fc8; char padcc[12];
    unsigned fd8,fdc,fe0,fe4,fe8,fec,ff0,ff4; float ff8;
    virtual void baseVirtual();
    CPathAgent(Arg_1047b0*);
};
CPathAgent::CPathAgent(Arg_1047b0* arg) : FUN_000fc760(arg) {
 f5c=0; f6c=0;
 f60=arg->FUN_000fefa0(); f60->retain();
 f64=0; f68=0; f70=0; f74=0; f78=0;
 f88=0; f89=1; f90=0; f91=0; f9c=0;
 f8c=1.0f; f94=1.0f; f98=1.0f;
 fc4=0; fc0=0; fbc=0; fe0=0; fdc=0; fd8=0; fe4=0; ff0=0; fec=0; fe8=0; ff4=0; ff8=999.0f;
 Obj_1047b0* p=(Obj_1047b0*)FUN_0008d690(0x38);
 fc8=p ? p->FUN_00109ba0() : 0;
 fc8->retain();
}