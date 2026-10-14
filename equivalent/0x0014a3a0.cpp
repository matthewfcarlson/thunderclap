// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_0014a3a0 @ 0x0014a3a0
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_00146990();
extern "C" void FUN_001469c0();
extern "C" void FUN_00146a00();
struct FUN_00234960 { FUN_00234960(const char*); virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
struct FUN_00234e50 { FUN_00234e50(const char*); virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
namespace hulkfight { namespace motion { class CivilianDetachTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 { ParamFloatConstRange(const char* s):FUN_00234960(s) {} virtual void slot0(); };
template<class T> struct ParamVector : FUN_00234e50 { ParamVector(const char* s):FUN_00234e50(s) {} virtual void slot0(); };
}
extern int DAT_004e0fe8;
extern int DAT_004e0fe4;
extern "C" void __cdecl FUN_002347b0(void*, void**, int);
void FUN_0014a3a0() {
 if (!DAT_004e0fe8) {
 void* items[3];
 typedef fight::ParamFloatConstRange<hulkfight::motion::CivilianDetachTrack> FloatParam;
 typedef fight::ParamVector<hulkfight::motion::CivilianDetachTrack> VectorParam;
 FloatParam* a = (FloatParam*)FUN_0008d690(24);
 if(a) { a = new(a) FloatParam("timeBegin"); a->callback = FUN_00146990; }
 items[0]=a;
 VectorParam* b=(VectorParam*)FUN_0008d690(24);
 if(b) { b = new(b) VectorParam("offset"); b->callback=FUN_001469c0; }
 items[1]=b;
 VectorParam* c=(VectorParam*)FUN_0008d690(24);
 if(c) { c = new(c) VectorParam("orient"); c->callback=FUN_00146a00; }
 items[2]=c;
 FUN_002347b0(&DAT_004e0fe4,items,3);
 }
 ++DAT_004e0fe8;
}