// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 20/20)
// FUN_001d1180 @ 0x001d1180
// ScriptHandler's function list (include/decls/data/script.h ScriptFunctionList): inserts a Function by its key,
// in order; false when the list is full.
#include "decls/data/script.h"

extern "C" int __cdecl FUN_00096600(const char *a, const char *b);

class SortedList : public ScriptFunctionList {
public:
    bool FUN_001d1180(ScriptFunctionView *e);
};

bool SortedList::FUN_001d1180(ScriptFunctionView *e)
{
    const char *name = e->f.key;
    if (count >= 0x400)
        return false;
    int pos = -1;
    if (name != 0 && *name != 0) {
        for (int i = 0; i < count; i++) {
            const char *other = ((ScriptFunctionView *)items[i])->f.key;
            if (other == 0 || *other == 0 || FUN_00096600(other, name) >= 0) {
                pos = i;
                break;
            }
        }
    }
    if (pos < 0)
        pos = count;
    for (int j = count; j > pos; j--)
        items[j] = items[j - 1];
    items[pos] = e;
    count++;
    return true;
}
