// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 13/13)
// FUN_00221610 @ 0x00221610
// FUN_00221610 @ 0x00221610
struct Token_221610 { int type; int value; int pad; int left; int right; }; struct Context { char pad[0x24]; int count; char pad2[0xc]; unsigned char limit; };
void __cdecl FUN_00220d90(Context*, Token_221610*);
// equiv-conv: FUN_00220ab0 ecx eax
void FUN_00220ab0(Context*, Token_221610*);
// equiv-conv: FUN_00220f80 eax stack
extern "C" void __cdecl FUN_00220f80(void *, int *);
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
// equiv-conv: target esi edi
int target(Token_221610* t, Context* c) { FUN_00220d90(c,t); switch(t->type) { case 1: case 3: t->type=2; break; case 2: case 4: t->type=3; break; case 9: FUN_00220ab0(c, t); break; case 10: case 11: FUN_00220f80((Context *)c,(int *)(Token_221610 *)t); if(t->type==11 && t->value >= c->limit && t->value<250) --c->count; t->value=FUN_00220bd0((Context *)c,18,0,(int)(t->value),0); t->type=10; break; } int r=t->right; t->right=t->left; t->left=r; return r; }
