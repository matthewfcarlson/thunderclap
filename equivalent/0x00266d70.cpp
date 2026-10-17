// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00266d70 @ 0x00266d70
#include "decls/data/engine/unknown.h"

struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int value);
};
void FUN_00270380();
void FUN_00270530();
void FUN_00266d70()
{
    FUN_00270380();
    (*(unsigned char*)&DAT_00527f5c) = 0;
    (*(Manager**)&DAT_00527f58)->slot2(0);
    FUN_00270530();
}
