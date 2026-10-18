// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002616d0 @ 0x002616d0
// Script "(>= a b)" style comparison: evaluates two sub-expressions and returns "t" or "nil".
struct Parser;
const char* __cdecl FUN_002611b0(Parser* p);   // parse the next operand, returns its text
float __cdecl FUN_00260d00(const char* text);  // text to number

const char* __cdecl FUN_002616d0(Parser* p)
{
    const char* a = FUN_002611b0(p);
    const char* b = FUN_002611b0(p);
    float fa = FUN_00260d00(a);
    float fb = FUN_00260d00(b);
    return (fb <= fa) ? "t" : "nil";
}
