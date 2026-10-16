// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016bc20 @ 0x0016bc20
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_00165940();
extern "C" void __cdecl FUN_00165950();
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
typedef fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition> Entry_16bc20;
extern "C" void __cdecl FUN_002347b0(void*, Entry_16bc20**, unsigned int);
void __cdecl FUN_0016bc20() {
 if (!DAT_004e129c) {
 Entry_16bc20* entries[2];
 Entry_16bc20* p = (Entry_16bc20*)FUN_0008d690(32);
 if (p) {
 unsigned int n = (*(unsigned int*)&DAT_00427760);
 p->FUN_00234cc0("compare");
 new (p) Entry_16bc20;
 p->values = ((char*)&DAT_00427758);
 p->count = n;
 p->callback = FUN_00165940;
 }
 entries[0] = p;
 p = (Entry_16bc20*)FUN_0008d690(32);
 if (p) {
 unsigned int n = (*(unsigned int*)&DAT_003fb900);
 p->FUN_00234cc0("rageMode");
 new (p) Entry_16bc20;
 p->values = ((char*)&DAT_00496fd8);
 p->count = n;
 p->callback = FUN_00165950;
 }
 entries[1] = p;
 FUN_002347b0(((char*)&DAT_004e1298), entries, 2);
 }
 ++DAT_004e129c;
}
