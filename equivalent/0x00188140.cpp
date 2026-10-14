// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_00188140 @ 0x00188140
inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0017fe40();
void __cdecl FUN_0017fe60();
void __cdecl FUN_0017fe80();
namespace hulkfight { namespace motion { class PropSetStateByIndexTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void v0();
 char fields[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_00234960(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void v0();
 char fields[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_002348e0(const char*);
};
}
extern unsigned int DAT_004e14ac;
extern unsigned int DAT_004e14a8;
void __cdecl FUN_002347b0(void*,void**,int);
void FUN_00188140() {
 if (DAT_004e14ac == 0) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack> FloatParam;
 typedef fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack> IntParam;
 FloatParam* a = (FloatParam*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new (a) FloatParam; a->callback=FUN_0017fe40; }
 params[0]=a;
 IntParam* b=(IntParam*)FUN_0008d690(24);
 if(b) { b->FUN_002348e0("attachmentIndex"); new (b) IntParam; b->callback=FUN_0017fe60; }
 params[1]=b;
 IntParam* c=(IntParam*)FUN_0008d690(24);
 if(c) { c->FUN_002348e0("state"); new (c) IntParam; c->callback=FUN_0017fe80; }
 params[2]=c;
 FUN_002347b0(&DAT_004e14a8,params,3);
 }
 ++DAT_004e14ac;
}
