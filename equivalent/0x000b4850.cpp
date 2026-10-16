// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_000b4850 @ 0x000b4850
#include "decls/address.h"
#include "decls/data/game/unknown.h"
extern unsigned int DAT_004d9968; extern void __fastcall __security_check_cookie(unsigned int);
struct Manager_b4850 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); }; extern Manager_b4850* __cdecl FUN_000fc1b0();
  extern char DAT_0049dba4, DAT_0049f48c, DAT_0049f470;
extern void __cdecl FUN_000fc020(char*,int,const char*,const char*,const char*,const char*,const char*,const char*);
extern void __cdecl FUN_000fc000(char*,int,const char*,const char*,const char*,const char*,const char*,const char*);
extern int __cdecl FUN_00267760(char*,int,const char*,...);
extern void* __cdecl FUN_000fc260(const char*);
struct Value_b4850 { void FUN_000f8500(const char*,Manager_b4850*,int); void FUN_000f79a0(const char*,Manager_b4850*); };
struct Widget_b4850 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void update(); char pad[20]; Value_b4850 value; };
extern Widget_b4850* __cdecl FUN_00344e74(void*,int,char*,char*,int);
struct Screen_b4850 { void FUN_001cc620(int); }; struct World { char pad[44]; Screen_b4850* screen; }; 
void __stdcall FUN_000b4850(const char* title,const char* format,const char* a,const char* b,const char* c,const char* d,const char* e) {
 unsigned int cookie=DAT_004d9968;
 Manager_b4850* m=FUN_000fc1b0(); const char* fmt=m->FUN_000f7220(m->FUN_000f7d30(format));
 m=FUN_000fc1b0(); if(m->FUN_000f7220(m->FUN_000f7d30(a))) { m=FUN_000fc1b0(); a=m->FUN_000f7220(m->FUN_000f7d30(a)); }
 m=FUN_000fc1b0(); if(m->FUN_000f7220(m->FUN_000f7d30(b))) { m=FUN_000fc1b0(); b=m->FUN_000f7220(m->FUN_000f7d30(b)); }
 m=FUN_000fc1b0(); if(m->FUN_000f7220(m->FUN_000f7d30(c))) { m=FUN_000fc1b0(); c=m->FUN_000f7220(m->FUN_000f7d30(c)); }
 m=FUN_000fc1b0(); if(m->FUN_000f7220(m->FUN_000f7d30(d))) { m=FUN_000fc1b0(); d=m->FUN_000f7220(m->FUN_000f7d30(d)); }
 m=FUN_000fc1b0(); if(m->FUN_000f7220(m->FUN_000f7d30(e))) { m=FUN_000fc1b0(); e=m->FUN_000f7220(m->FUN_000f7d30(e)); }
 if(fmt) FUN_000fc020(((char*)&DAT_004ddc18),256,fmt,a,b,c,d,e); else { char buffer[256]; FUN_00267760(buffer,256,(*(unsigned char*)&DAT_004dd8e8)?"[NITB] %s":"%s",format); FUN_000fc000(((char*)&DAT_004ddc18),256,buffer,a,b,c,d,e); }
 Widget_b4850* w=FUN_00344e74(FUN_000fc260("fullscreen_message_title"),0,&DAT_0049dba4,&DAT_0049f48c,0); if(w) { m=FUN_000fc1b0(); w->value.FUN_000f8500(title,m,1); w->update(); }
 w=FUN_00344e74(FUN_000fc260("fullscreen_message_text"),0,&DAT_0049dba4,&DAT_0049f470,0); if(w) { m=FUN_000fc1b0(); w->value.FUN_000f79a0(((char*)&DAT_004ddc18),m); w->update(); }
 DAT_004dd700->screen->FUN_001cc620(10);
 __security_check_cookie(cookie);
}