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
void __cdecl FUN_002141d0(TailRecord *record, TailArgument *argument)
{
    record->first = ((char*)&DAT_003f335c);
    record->second = ((char*)&DAT_003f335c);
    record->index = -1;
    record->next = -1;
    record->name = ((char*)&DAT_0042662c);
    record->description = ((char*)&DAT_00426634);
    FUN_00216340(record->text, ((char*)&DAT_00426634), 60);
    record->state = 0;
    *argument->result = 0;
}