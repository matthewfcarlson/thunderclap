// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_001d16a0 @ 0x001d16a0
// ScriptHandler (include/decls/data/script.h): adds a watched number (dbg_AddWatch) while there is room and the
// name fits.
#include "decls/data/script.h"
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
struct Target_1d16a0 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d16a0(const char *name, float val);
};
void Target_1d16a0::FUN_001d16a0(const char *name, float val)
{
    if (watches.count < 0x100) {
        const char *p = name;
        while (*p != 0)
            p++;
        if (p - name < 0x40) {
            FUN_000964a0(watches.names[watches.count], 0x40, "%s", name);
            watches.values[watches.count] = val;
            watches.count = watches.count + 1;
        }
    }
}
