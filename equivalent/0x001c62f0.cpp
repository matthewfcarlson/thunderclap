// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 30/30)
// FUN_001c62f0 @ 0x001c62f0
struct Mode_1c62f0 { int FUN_000897e0(); };
struct Manager_1c62f0 { Mode_1c62f0* FUN_00086310(); };
struct Root_1c62f0 { char pad[0x54]; Manager_1c62f0* manager; };
extern Root_1c62f0* DAT_004dd700;
extern "C" long __cdecl atol(const char*);
long __cdecl FUN_001c62c0(const char*, const char*);
long __cdecl FUN_001c62f0(const char* text, char marker) {
 if (!text) return -1;
 if (DAT_004dd700->manager->FUN_00086310()->FUN_000897e0()) {
  if (marker != 'R') return -1;
  const char* end = text;
  while (*end) ++end;
  if ((unsigned)(end-text) < 4) return 0;
  end = text;
  while (*end) ++end;
  return atol(end-3);
 }
 const char* p=text;
 while (*p && *p != marker) ++p;
 if (!*p) return -1;
 const char* start=++p;
 if (!*p) return -1;
 while (*p && *p >= '0' && *p <= '9') ++p;
 if (p == start) return -1;
 return FUN_001c62c0(start,p);
}
