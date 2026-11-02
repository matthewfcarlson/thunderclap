// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 18/18)
// FUN_00221280 @ 0x00221280
struct Token_221280 { int type; unsigned int value; unsigned int extra; };
struct ContextData_221280 { char pad[8]; unsigned int value; };
struct Context { char pad0[12]; ContextData_221280* data; char pad1[20]; int count; char pad2[12]; unsigned char threshold; };
// equiv-conv: FUN_00220fe0 eax stack stack
extern void __cdecl FUN_00220fe0(Context*, Token_221280*, unsigned int);
extern "C" int __cdecl FUN_00221190(void *, void *);
extern unsigned int __cdecl FUN_00221200(Context*, Token_221280*);
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00221280(void * context_, void * operation, void * operand) {
    Context * context = (Context *)context_;
 unsigned int result;
 switch(((Token_221280 *)operation)->type) {
 case 5:
  if(((Token_221280 *)operand)->type == 11 && (int)((Token_221280 *)operand)->value >= context->threshold && (int)((Token_221280 *)operand)->value < 250) --context->count;
  FUN_00220fe0(context, ((Token_221280 *)operand), ((Token_221280 *)operation)->value);
  return;
 case 6:
  result = ((unsigned int)FUN_00221190((Context *)context, (Token_221280 *)((Token_221280 *)operand)));
  FUN_00220bd0((Context *)context, 8, (unsigned int)result, ((Token_221280 *)operation)->value, 0);
  break;
 case 7:
  result = ((unsigned int)FUN_00221190((Context *)context, (Token_221280 *)((Token_221280 *)operand)));
  FUN_00220b20((Context *)context, ((result << 18) | ((Token_221280 *)operation)->value) << 6 | 7, context->data->value);
  break;
 case 8:
  result = FUN_00221200(context, ((Token_221280 *)operand));
  FUN_00220bd0((Context *)context, 9, (unsigned int)(((Token_221280 *)operation)->value), ((Token_221280 *)operation)->extra, result);
  break;
 }
 if(((Token_221280 *)operand)->type == 11 && (int)((Token_221280 *)operand)->value >= context->threshold && (int)((Token_221280 *)operand)->value < 250) --context->count;
}
