// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033c730 @ 0x0033c730
struct Capture { int start; int length; };
struct Pattern { char padding[8]; void* errorContext; int captureCount; Capture captures[1]; };
extern "C" int __cdecl FUN_00338e20(void*, const char*);
extern "C" int __cdecl FUN_0033c7e0(Pattern*, int, int);
// equiv-conv: FUN_0033c730 esi ebx stack
int FUN_0033c730(Pattern* pattern, int position, int argument)
{
    int index = pattern->captureCount - 1;
    while (index >= 0 && pattern->captures[index].length != -1)
        --index;
    if (index < 0)
        index = FUN_00338e20(pattern->errorContext, "invalid pattern capture");
    pattern->captures[index].length = position - pattern->captures[index].start;
    int result = FUN_0033c7e0(pattern, position, argument);
    if (result == 0)
        pattern->captures[index].length = -1;
    return result;
}