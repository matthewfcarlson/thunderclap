// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00219e90 @ 0x00219e90
struct Value { int type; union { float real; int integer; } data; };
extern void __cdecl FUN_00219dc0(int, int);
extern void __cdecl FUN_00219e50(int, int);
extern void __cdecl FUN_00219d80(int);
void __cdecl FUN_00219e90(int context, const Value *value)
{
    if (value->type == 3) {
        int integer = (int)value->data.real;
        if (value->data.real == (float)integer) {
            FUN_00219dc0(context, integer);
            return;
        }
    } else if (value->type == 4) {
        FUN_00219e50(context, value->data.integer);
        return;
    }
    FUN_00219d80(context);
}