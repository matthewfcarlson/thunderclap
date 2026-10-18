// STATUS: equivalent (tools/equiv.py level 3: 19947 inputs, branch coverage 4/4)
// FUN_0021cd90 @ 0x0021cd90
// FUN_0021cd90 @ 0x0021cd90
struct Context { char pad[0x24]; int saved; };
struct Node { char pad[0xc]; int kind; char pad2[0xc]; Context* context; };
struct Info_21cd90 { int unused; int value; };
struct State_21cd90 { char pad[0x14]; Info_21cd90* info; int count; };
struct Value_21cd90 { int type; int value; int extra; int a; int b; };
// equiv-conv: FUN_0021c240 ecx esi
void FUN_0021c240(const char*, Context*);
// equiv-conv: FUN_0021c3d0 esi
int FUN_0021c3d0(Node*);
int __cdecl FUN_002209b0(Context*, int);
// equiv-conv: FUN_0021cd30 eax edi
void FUN_0021cd30(Node*, Value_21cd90*);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(Node*, int);
int __cdecl FUN_00221200(Context*, Value_21cd90*);
void __cdecl FUN_0021ded0(Node*, Value_21cd90*, int);
int __cdecl FUN_00220bd0(Context*, int, int, int, int);
int __cdecl target(Node* node, State_21cd90* state) {
 Context* context = node->context;
 int saved = context->saved;
 Value_21cd90 left, right;
 if(node->kind == 0x116) {
  if(state->count > 0x7ffffffd) FUN_0021c240("items in a constructor", context);
  ++state->count;
  int v = FUN_0021c3d0(node);
  int result = FUN_002209b0(node->context,v);
  left.a = -1; left.b = -1; left.type = 4; left.value = result;
 } else FUN_0021cd30(node, &left);
 FUN_0021c2e0(node, 0x3d);
 FUN_00221200(context,&left);
 FUN_0021ded0(node,&right,0);
 int r = FUN_00221200(context,&right);
 int l = FUN_00221200(context,&left);
 int result = FUN_00220bd0(context,9,state->info->value,l,r);
 context->saved=saved;
 return result;
}
