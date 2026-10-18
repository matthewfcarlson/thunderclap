// STATUS: equivalent (tools/equiv.py level 3: 15902 inputs, branch coverage 10/10)
// FUN_00220fe0 @ 0x00220fe0
// FUN_00220fe0 @ 0x00220fe0
struct Record_220fe0 { int type; int value; int unused; int left; int right; };
struct Info_220fe0 { int a,b,c; };
struct Context { char pad[12]; Info_220fe0* info; char pad2[8]; int position; int savedPosition; int link; };
// equiv-conv: FUN_00220e90 eax ebx esi
void __cdecl FUN_00220e90(Context*, Record_220fe0*, int);
void __cdecl FUN_002207c0(Context*, int*, int);
// equiv-conv: FUN_002205a0 ecx eax stack
int __cdecl FUN_002205a0(int, Context*, int);
// equiv-conv: FUN_00220cd0 eax stack
int __cdecl FUN_00220cd0(int, Context*);
int __cdecl FUN_00220b20(Context*, int, int);
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
void __cdecl FUN_00220650(int, Context*, int, int, int, int, int);
// equiv-conv: target eax stack stack
int __cdecl target(Context* ctx, Record_220fe0* rec, int flag) {
 FUN_00220e90(ctx, rec, flag);
 if(rec->type==9) FUN_002207c0(ctx,&rec->left,rec->value);
 if(rec->left!=rec->right) {
  int right=rec->right;
  int a=-1,b=-1;
  if(FUN_002205a0(rec->left, ctx, 1) || FUN_002205a0(right, ctx, 0)) {
   int link=-1;
   if(rec->type!=9) link=FUN_00220cd0(rec->type,ctx);
   ctx->savedPosition=ctx->position;
   a=FUN_00220b20(ctx,(flag<<24)|0x42,ctx->info->c);
   ctx->savedPosition=ctx->position;
   b=FUN_00220b20(ctx,(flag<<24)|0x8002,ctx->info->c);
   ctx->savedPosition=ctx->position;
   FUN_002207c0(ctx,&ctx->link,link);
  }
  int position=ctx->position;
  ctx->savedPosition=position;
  FUN_00220650(rec->right, ctx, a, 255, position, flag, a);
  FUN_00220650(rec->left, ctx, position, flag, b, 255, b);
 }
 rec->left=-1; rec->right=-1; rec->value=flag; rec->type=11;
 return -1;
}
