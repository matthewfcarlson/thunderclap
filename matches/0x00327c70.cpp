#include "decls/data/engine/pure3d.h"

extern "C" int __cdecl strcmp(const char*, const char*);
typedef int(__cdecl* Handler_327c70)(int, const char*, int);
struct Entry_327c70 {
    char name[64];
    Handler_327c70 handler;
    int context;
};
int __cdecl FUN_00327c70(int first, const char* name, int context) {
    int count = (*(int*)&DAT_005555c0);
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, ((Entry_327c70*)&DAT_005555c8)[i].name) == 0) {
            int replacement = ((Entry_327c70*)&DAT_005555c8)[i].context;
            if (replacement)
                context = replacement;
            return ((Entry_327c70*)&DAT_005555c8)[i].handler(first, name, context);
        }
    }
    return ((Entry_327c70*)&DAT_005555c8)[0].handler(first, name, context);
}