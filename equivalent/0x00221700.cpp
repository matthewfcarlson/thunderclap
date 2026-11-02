// STATUS: equivalent (tools/equiv.py level 3: 17400 inputs, branch coverage 14/14)
// FUN_00221700 @ 0x00221700
// FUN_00221700 @ 0x00221700
struct Constant_221700 { int type; float value; };
struct Pool_221700 { char pad[8]; Constant_221700* constants; };
struct ContextData_221700 { char pad[8]; int value; };
struct Context { Pool_221700* pool; char pad4[8]; ContextData_221700* data; char pad10[20]; int count; char pad28[12]; unsigned char limit; };
struct Node { int type; int value; int unused; int left; int right; };
extern "C" int __cdecl FUN_00221190(void *, void *);
void __cdecl FUN_00220d90(Context*,Node*);
int __cdecl FUN_002209e0(Context*,float);
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
// equiv-conv: FUN_00221610 esi edi
void FUN_00221610(Node*,Context*);
extern "C" void __cdecl FUN_00221700(void * context_,int flag,void * node) {
    Context * context = (Context *)context_;
 if(flag) { FUN_00221610(((Node *)node),context); return; }
 if(((Node *)node)->left != ((Node *)node)->right) FUN_00221190((Context *)context,(Node *)((Node *)node)); else FUN_00220d90(context,((Node *)node));
 if(((Node *)node)->type==4) {
  Constant_221700* constant=&context->pool->constants[((Node *)node)->value];
  if(constant->type==3) { ((Node *)node)->value=FUN_002209e0(context,-constant->value); return; }
 }
 FUN_00221190((Context *)context,(Node *)((Node *)node));
 if(((Node *)node)->type==11 && ((Node *)node)->value >= context->limit && ((Node *)node)->value <250) --context->count;
 ((Node *)node)->value=FUN_00220b20((Context *)context,(int)((int)(((unsigned int)((Node *)node)->value <<15)|17)),(int)(context->data->value));
 ((Node *)node)->type=10;
}
