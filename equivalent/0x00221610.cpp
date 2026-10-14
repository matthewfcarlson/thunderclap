// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 12/13, incomplete)
// FUN_00221610 @ 0x00221610
struct Token { int type; int value; int pad; int left; int right; }; struct Context { char pad[0x24]; int count; char pad2[0xc]; unsigned char limit; };
void __cdecl FUN_00220d90(Context*, Token*);
// equiv-conv: FUN_00220ab0 eax ecx
void FUN_00220ab0(Token*,Context*);
// equiv-conv: FUN_00220f80 eax stack
void FUN_00220f80(Context*,Token*);
int __cdecl FUN_00220bd0(Context*,int,int,int,int);
// equiv-conv: target esi edi
int target(Token* t, Context* c) { FUN_00220d90(c,t); switch(t->type) { case 1: case 3: t->type=2; break; case 2: case 4: t->type=3; break; case 9: FUN_00220ab0(t,c); break; case 10: case 11: FUN_00220f80(c,t); if(t->type==11 && t->value >= c->limit && t->value<250) --c->count; t->value=FUN_00220bd0(c,18,0,t->value,0); t->type=10; break; } int r=t->right; t->right=t->left; t->left=r; return r; }