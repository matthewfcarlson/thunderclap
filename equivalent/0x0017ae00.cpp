// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_0017ae00 @ 0x0017ae00
inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_0016fa60(); void FUN_0016fa70(); void FUN_0016fa90();
struct FloatBase_17ae00 { virtual void slot0(); char padding[12]; void (*callback)(); int tail; void FUN_00234960(const char*); };
struct BoolBase { virtual void slot0(); char padding[12]; void (*callback)(); int tail; void FUN_00234860(const char*); };
namespace hulkfight { namespace motion { class ChargeClearTrack; } }
namespace fight {
 template<class T> struct ParamFloatConstRange : FloatBase_17ae00 { virtual void slot0(); };
 template<class T> struct ParamBool : BoolBase { virtual void slot0(); };
}
extern unsigned int DAT_004e13ac;
extern int DAT_004e13a8;
void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl target() {
 if (!DAT_004e13ac) {
 void* params[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack> FloatParam;
 typedef fight::ParamBool<hulkfight::motion::ChargeClearTrack> BoolParam;
 FloatParam* a = (FloatParam*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); a = new(a) FloatParam; a->callback = FUN_0016fa60; }
 params[0] = a;
 FloatParam* b = (FloatParam*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("timeEnd"); b = new(b) FloatParam; b->callback = FUN_0016fa70; }
 params[1] = b;
 BoolParam* c = (BoolParam*)FUN_0008d690(24);
 if(c) { c->FUN_00234860("clearOnBegin"); c = new(c) BoolParam; c->callback = FUN_0016fa90; }
 params[2] = c;
 FUN_002347b0(&DAT_004e13a8,params,3);
 }
 ++DAT_004e13ac;
}
