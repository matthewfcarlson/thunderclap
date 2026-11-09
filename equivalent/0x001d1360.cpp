// STATUS: equivalent (tools/equiv.py level 3: 2891 inputs, branch coverage 20/20)
// FUN_001d1360 @ 0x001d1360
// ScriptHandler's function list (include/decls/data/script.h ScriptFunctionList): deletes the Function whose key is
// the given Function's key and closes the gap.
#include "decls/data/script.h"
extern "C" int __cdecl FUN_00096600(const char *a, const char *b);
struct Item_1d1360 : public ScriptFunctionFields {
    virtual ~Item_1d1360() throw();
};
class ItemList_1d1360 : public ScriptFunctionList {
public:
    bool FUN_001d1360(ScriptFunctionView *key);
};
bool ItemList_1d1360::FUN_001d1360(ScriptFunctionView *key)
{
    const char *want = key->f.key;
    if (want == 0 || *want == 0)
        return false;
    for (int i = 0; i < count; i++) {
        const char *name = ((Item_1d1360 *)items[i])->key;
        if (name != 0 && *name != 0 && FUN_00096600(name, want) == 0) {
            if (items[i] != 0) {
                delete (Item_1d1360 *)items[i];
                items[i] = 0;
            }
            for (int j = i + 1; j < count; j++)
                items[j - 1] = items[j];
            items[count - 1] = 0;
            count--;
            return true;
        }
    }
    return false;
}
