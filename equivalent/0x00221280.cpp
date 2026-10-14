// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 18/18)
// FUN_00221280 @ 0x00221280
struct Token { int type; unsigned int value; unsigned int extra; };
struct ContextData { char pad[8]; unsigned int value; };
struct Context { char pad0[12]; ContextData* data; char pad1[20]; int count; char pad2[12]; unsigned char threshold; };
// equiv-conv: FUN_00220fe0 eax stack stack
extern void __cdecl FUN_00220fe0(Context*, Token*, unsigned int);
extern unsigned int __cdecl FUN_00221190(Context*, Token*);
extern unsigned int __cdecl FUN_00221200(Context*, Token*);
extern void __cdecl FUN_00220b20(Context*, unsigned int, unsigned int);
extern void __cdecl FUN_00220bd0(Context*, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_00221280(Context* context, Token* operation, Token* operand) {
 unsigned int result;
 switch(operation->type) {
 case 5:
  if(operand->type == 11 && (int)operand->value >= context->threshold && (int)operand->value < 250) --context->count;
  FUN_00220fe0(context, operand, operation->value);
  return;
 case 6:
  result = FUN_00221190(context, operand);
  FUN_00220bd0(context, 8, result, operation->value, 0);
  break;
 case 7:
  result = FUN_00221190(context, operand);
  FUN_00220b20(context, ((result << 18) | operation->value) << 6 | 7, context->data->value);
  break;
 case 8:
  result = FUN_00221200(context, operand);
  FUN_00220bd0(context, 9, operation->value, operation->extra, result);
  break;
 }
 if(operand->type == 11 && (int)operand->value >= context->threshold && (int)operand->value < 250) --context->count;
}
