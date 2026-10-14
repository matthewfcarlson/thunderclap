// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016bc20 @ 0x0016bc20
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_00165940();
extern "C" void __cdecl FUN_00165950();
extern unsigned int DAT_00427760;
extern unsigned int DAT_003fb900;
extern char DAT_00427758;
extern char DAT_00496fd8;
extern unsigned int DAT_004e129c;
extern char DAT_004e1298;
namespace hulkfight { namespace motion { class RageModeStateCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 const void* values;
 unsigned int count;
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234cc0(const char*);
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition> Entry;
extern "C" void __cdecl FUN_002347b0(void*, Entry**, unsigned int);
void __cdecl FUN_0016bc20() {
 if (!DAT_004e129c) {
 Entry* entries[2];
 Entry* p = (Entry*)FUN_0008d690(32);
 if (p) {
 unsigned int n = DAT_00427760;
 p->FUN_00234cc0("compare");
 new (p) Entry;
 p->values = &DAT_00427758;
 p->count = n;
 p->callback = FUN_00165940;
 }
 entries[0] = p;
 p = (Entry*)FUN_0008d690(32);
 if (p) {
 unsigned int n = DAT_003fb900;
 p->FUN_00234cc0("rageMode");
 new (p) Entry;
 p->values = &DAT_00496fd8;
 p->count = n;
 p->callback = FUN_00165950;
 }
 entries[1] = p;
 FUN_002347b0(&DAT_004e1298, entries, 2);
 }
 ++DAT_004e129c;
}
