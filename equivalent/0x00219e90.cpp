// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00219e90 @ 0x00219e90
struct Value { int type; union { float real; int integer; } data; };
extern int* __cdecl FUN_00219dc0(int, int);
extern int* __cdecl FUN_00219e50(int, int);
// equiv-conv: FUN_00219d80 edi stack
extern int* __cdecl FUN_00219d80(const Value *, int);
int* __cdecl FUN_00219e90(int context, const Value *value)
{
    if (value->type == 3) {
        int integer = (int)value->data.real;
        if (value->data.real == (float)integer) {
            return FUN_00219dc0(context, integer);
        }
    } else if (value->type == 4) {
        return FUN_00219e50(context, value->data.integer);
    }
    return FUN_00219d80(value, context);
}