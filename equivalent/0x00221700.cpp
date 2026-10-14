// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 13/14, incomplete)
// FUN_00221700 @ 0x00221700
struct Constant { int type; float value; };
struct Pool { char pad[8]; Constant* constants; };
struct ContextData { char pad[8]; int value; };
struct Context { Pool* pool; char pad4[8]; ContextData* data; char pad10[20]; int count; char pad28[12]; unsigned char limit; };
struct Node { int type; int value; int unused; int left; int right; };
void __cdecl FUN_00221190(Context*,Node*);
void __cdecl FUN_00220d90(Context*,Node*);
int __cdecl FUN_002209e0(Context*,float);
int __cdecl FUN_00220b20(Context*,int,int);
// equiv-conv: FUN_00221610 edi eax esi
void FUN_00221610(Context*,int,Node*);
void __cdecl FUN_00221700(Context* context,int flag,Node* node) {
 if(flag) { FUN_00221610(context,flag,node); return; }
 if(node->left != node->right) FUN_00221190(context,node); else FUN_00220d90(context,node);
 if(node->type==4) {
  Constant* constant=&context->pool->constants[node->value];
  if(constant->type==3) { node->value=FUN_002209e0(context,-constant->value); return; }
 }
 FUN_00221190(context,node);
 if(node->type==11 && node->value >= context->limit && node->value <250) --context->count;
 node->value=FUN_00220b20(context,(int)(((unsigned int)node->value <<15)|17),context->data->value);
 node->type=10;
}
