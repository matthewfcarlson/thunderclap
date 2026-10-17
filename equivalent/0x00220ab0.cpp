// STATUS: equivalent (tools/equiv.py level 3: 2720 inputs, branch coverage 4/4)
// FUN_00220ab0 @ 0x00220ab0
#include "decls/data/engine/unknown.h"

struct WordBuffer { char pad[12]; unsigned int *words; };
struct Cursor { int unused; int index; };
// equiv-conv: FUN_00220ab0 ecx eax
void FUN_00220ab0(WordBuffer **buffer, Cursor *cursor)
{
    unsigned int *word = (*buffer)->words + cursor->index;
    if (cursor->index > 0 && ((signed char*)&DAT_00426ba4)[word[-1] & 63] < 0)
        --word;
    unsigned int value = *word;
    *word = (value & 0x00ffffff) | ((value & 0xff000000) == 0 ? 0x01000000 : 0);
}