// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 0/0)
// FUN_002141d0 @ 0x002141d0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

void __cdecl FUN_00216340(char *destination, const char *source, int length);
struct TailRecord {
    char reserved[4];
    char *first;
    char *second;
    const char *name;
    const char *description;
    int index;
    int state;
    int next;
    char text[60];
};
struct TailArgument {
    char reserved[8];
    int *result;
};
// equiv-conv: FUN_002141d0 esi stack
extern "C" void __cdecl FUN_002141d0(void *record, void *argument)
{
    ((TailRecord *)record)->first = ((char*)&DAT_003f335c);
    ((TailRecord *)record)->second = ((char*)&DAT_003f335c);
    ((TailRecord *)record)->index = -1;
    ((TailRecord *)record)->next = -1;
    ((TailRecord *)record)->name = ((char*)&DAT_0042662c);
    ((TailRecord *)record)->description = ((char*)&DAT_00426634);
    FUN_00216340(((TailRecord *)record)->text, ((char*)&DAT_00426634), 60);
    ((TailRecord *)record)->state = 0;
    *((TailArgument *)argument)->result = 0;
}