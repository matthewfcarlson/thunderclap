// STATUS: equivalent (tools/equiv.py level 3: 994 inputs, branch coverage 34/36, incomplete)
// FUN_001d1220 @ 0x001d1220
extern "C" int __cdecl FUN_00096670(const char*, const char*, unsigned int);
extern "C" int __cdecl FUN_00096600(const char*, const char*);
struct Entry_1d1220 { char pad[8]; char* text; };
struct Table_1d1220 { Entry_1d1220* entries[1024]; int count; char* FUN_001d1220(const char* prefix, const char* previous); };
char* Table_1d1220::FUN_001d1220(const char* prefix, const char* previous) {
 if (!prefix || !*prefix || count <= 0) return 0;
 int i = 0;
 for (;;) {
  const char* end = prefix; while (*end) ++end;
  if (FUN_00096670(prefix, entries[i]->text, (unsigned int)(end-prefix)) == 0) break;
  ++i; if (i >= count) return 0;
 }
 if (i < 0) return 0;
 int first = i;
 if (!previous || !*previous) return entries[i]->text;
 const char* end = prefix; while (*end) ++end;
 if (FUN_00096670(prefix, previous, (unsigned int)(end-prefix)) != 0) return entries[i]->text;
 while (i < count) {
  if (FUN_00096600(entries[i]->text, previous) == 0) {
   if (i >= 0 && i != count-1) {
    const char* finish = prefix; while (*finish) ++finish;
    if (FUN_00096670(prefix, entries[i+1]->text, (unsigned int)(finish-prefix)) == 0) return entries[i+1]->text;
   }
   return entries[first]->text;
  }
  ++i;
 }
 return entries[first]->text;
}