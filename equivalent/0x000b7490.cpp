// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 32/32)
// FUN_000b7490 @ 0x000b7490
struct Button_b7490 { char pad[0x141]; unsigned char enabled; };
struct Source_b7490 { const char* FUN_0008a2d0(); const char* FUN_0008a310(); };
extern const char* DAT_004067a4[];
extern char DAT_0049dba4;
extern char DAT_0049f4a4;
extern void* __cdecl FUN_000fc260(const char*);
extern Button_b7490* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Owner_b7490 { char pad[0x34]; Source_b7490* source; void FUN_000b7490(); };
void Owner_b7490::FUN_000b7490() {
 Button_b7490* button = FUN_00344e74(FUN_000fc260("abort_mission_button"),0,&DAT_0049dba4,&DAT_0049f4a4,0);
 if (!button || !source) return;
 const char* first = source->FUN_0008a2d0();
 const char* second = source->FUN_0008a310();
 unsigned char enabled = 0;
 if (first && second) {
  const unsigned char* a=(const unsigned char*)first;
  const unsigned char* b=(const unsigned char*)second;
  while (*a == *b && *a) { ++a; ++b; }
  enabled = (*a != *b);
  for (int i=0; DAT_004067a4[i]; ++i) {
   a=(const unsigned char*)first;
   b=(const unsigned char*)DAT_004067a4[i];
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) { enabled=0; break; }
  }
 }
 button->enabled=enabled;
}