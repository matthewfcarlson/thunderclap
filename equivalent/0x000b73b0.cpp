// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000b73b0 @ 0x000b73b0
struct Manager { int FUN_000f7240(unsigned __int64 id); };
extern Manager* __cdecl FUN_000fc1b0();
extern void* __cdecl FUN_000fc260(const char*);
extern int DAT_0049dba4; extern int DAT_0049f470;
struct Text { void FUN_000f8500(const char*,Manager*,int); void FUN_000f7a10(int,int); };
struct Dialog { virtual void v0(); virtual void v1(); virtual void v2(); virtual void close(); char pad[0x14]; Text text; };
extern Dialog* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct Source { void* FUN_0008a2f0(); };
extern unsigned __int64 __cdecl FUN_0027b020(void*);
struct Entry { unsigned __int64 id; char pad[32]; const char* FUN_0027b010(); };
extern char DAT_003f335c;
struct Owner { char pad0[0x34]; Source* source; char pad1[0x448]; Entry entries[1]; int FUN_000b4d70(unsigned __int64); void target(); };
void Owner::target() { if (!source) return; Dialog* d=FUN_00344e74(FUN_000fc260("mission_brief_text"),0,&DAT_0049dba4,&DAT_0049f470,0); if (!d) return; d->text.FUN_000f8500(&DAT_003f335c,FUN_000fc1b0(),0); void* p=source->FUN_0008a2f0(); if (!p) {d->close(); return;} int n=FUN_000b4d70(FUN_0027b020(p)); if(n!=-1) { Entry* e=&entries[n]; unsigned __int64 id=e->id; int x=FUN_000fc1b0()->FUN_000f7240(id); if(x!=-1) d->text.FUN_000f7a10(x,0); else {Manager* m=FUN_000fc1b0(); const char* s=e->FUN_0027b010(); d->text.FUN_000f8500(s,m,1);} } d->close(); }
