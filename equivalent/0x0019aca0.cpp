// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_0019aca0 @ 0x0019aca0
void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_001927d0();
void __cdecl FUN_001927e0();
void __cdecl FUN_00192800();
void __cdecl FUN_00192820();
struct Base {
 virtual void baseSlot();
 char padding[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
namespace hulkfight { namespace motion { class AccuracyLatencyTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange : Base {
 virtual void baseSlot();
};
}
typedef fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack> Param;
extern unsigned int DAT_004e1574;
extern unsigned int DAT_004e1570;
void __cdecl FUN_002347b0(void*, Param**, int);
void target() {
 if (DAT_004e1574 == 0) {
 Param* entries[4];
 void* p = FUN_0008d690(24);
 if(p) { ((Base*)p)->FUN_00234960("timeBegin"); entries[0] = new(p) Param; entries[0]->callback = FUN_001927d0; } else entries[0]=0;
 p = FUN_0008d690(24);
 if(p) { ((Base*)p)->FUN_00234960("timeEnd"); entries[1] = new(p) Param; entries[1]->callback = FUN_001927e0; } else entries[1]=0;
 p = FUN_0008d690(24);
 if(p) { ((Base*)p)->FUN_00234960("decay"); entries[2] = new(p) Param; entries[2]->callback = FUN_00192800; } else entries[2]=0;
 p = FUN_0008d690(24);
 if(p) { ((Base*)p)->FUN_00234960("decayScaler"); entries[3] = new(p) Param; entries[3]->callback = FUN_00192820; } else entries[3]=0;
 FUN_002347b0(&DAT_004e1570, entries, 4);
 }
 ++DAT_004e1574;
}