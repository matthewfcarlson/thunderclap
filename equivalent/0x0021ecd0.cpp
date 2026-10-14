// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// FUN_0021ecd0 @ 0x0021ecd0
struct Frame_21ecd0 { Frame_21ecd0* previous; int value; unsigned char saved, flag, active; };
struct State_21ecd0 { char pad0[12]; void* resource; char pad1[4]; Frame_21ecd0* frame; char pad2[12]; int level; char pad3[12]; unsigned char mode; };
struct Parser_21ecd0 { int a; int position; int savedPosition; int token; int tokenValue; int lookahead; int lookaheadValue; State_21ecd0* state; };
extern int __cdecl FUN_0021bbc0(Parser_21ecd0*, int*);
// equiv-conv: FUN_0021c3d0 esi
extern int FUN_0021c3d0(Parser_21ecd0*);
extern void __cdecl FUN_0021b060(Parser_21ecd0*, const char*);
// equiv-conv: FUN_0021e860 edi stack stack
extern void FUN_0021e860(Parser_21ecd0*, int, int);
// equiv-conv: FUN_0021ea60 ebx stack
extern void FUN_0021ea60(Parser_21ecd0*, int);
// equiv-conv: FUN_0021c340 eax edi stack
extern void FUN_0021c340(int, int, int);
// equiv-conv: FUN_0021c5b0 eax edx
extern void FUN_0021c5b0(void*, unsigned int);
extern void __cdecl FUN_00220bd0(State_21ecd0*, int, unsigned int, int, int);
extern void __cdecl FUN_00220d70(State_21ecd0*, int);
// equiv-conv: FUN_0021ecd0 eax stack
void FUN_0021ecd0(Parser_21ecd0* p, int arg) {
 State_21ecd0* s=p->state;
 Frame_21ecd0 local;
 local.value=-1; local.active=1; local.saved=s->mode; local.flag=0; local.previous=s->frame; s->frame=&local;
 p->savedPosition=p->position;
 if(p->lookahead!=0x11f) { p->token=p->lookahead; p->tokenValue=p->lookaheadValue; p->lookahead=0x11f; }
 else p->token=FUN_0021bbc0(p,&p->tokenValue);
 int result=FUN_0021c3d0(p);
 if(p->token==0x3d) FUN_0021e860(p,result,arg);
 else if(p->token==0x2c || p->token==0x10b) FUN_0021ea60(p,result);
 else FUN_0021b060(p,"`=' or `in' expected");
 FUN_0021c340(arg,0x106,0x108);
 Frame_21ecd0* f=s->frame;
 s->frame=f->previous;
 FUN_0021c5b0(s->resource,f->saved);
 if(f->flag) FUN_00220bd0(s,0x22,f->saved,0,0);
 s->level=s->mode;
 FUN_00220d70(s,f->value);
}
