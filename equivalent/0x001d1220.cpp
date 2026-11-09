// STATUS: equivalent (tools/equiv.py level 3: 994 inputs, branch coverage 34/36, incomplete)
// FUN_001d1220 @ 0x001d1220
// ScriptHandler's function list (include/decls/data/script.h ScriptFunctionList): the next key that starts with
// prefix after previous (completion).
#include "decls/data/script.h"
extern "C" int __cdecl FUN_00096670(const char*, const char*, unsigned int);
extern "C" int __cdecl FUN_00096600(const char*, const char*);
struct Table_1d1220 : public ScriptFunctionList { const char* FUN_001d1220(const char* prefix, const char* previous); };
#define KEY_1d1220(i) (((ScriptFunctionView*)items[i])->f.key)
const char* Table_1d1220::FUN_001d1220(const char* prefix, const char* previous) {
 if (!prefix || !*prefix || count <= 0) return 0;
 int i = 0;
 for (;;) {
  const char* end = prefix; while (*end) ++end;
  if (FUN_00096670(prefix, KEY_1d1220(i), (unsigned int)(end-prefix)) == 0) break;
  ++i; if (i >= count) return 0;
 }
 if (i < 0) return 0;
 int first = i;
 if (!previous || !*previous) return KEY_1d1220(i);
 const char* end = prefix; while (*end) ++end;
 if (FUN_00096670(prefix, previous, (unsigned int)(end-prefix)) != 0) return KEY_1d1220(i);
 while (i < count) {
  if (FUN_00096600(KEY_1d1220(i), previous) == 0) {
   if (i >= 0 && i != count-1) {
    const char* finish = prefix; while (*finish) ++finish;
    if (FUN_00096670(prefix, KEY_1d1220(i+1), (unsigned int)(finish-prefix)) == 0) return KEY_1d1220(i+1);
   }
   return KEY_1d1220(first);
  }
  ++i;
 }
 return KEY_1d1220(first);
}
