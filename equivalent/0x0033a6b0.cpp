// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033a6b0 @ 0x0033a6b0
extern "C" char* __cdecl strchr(const char*, int);
// equiv-conv: FUN_0033a6b0 edi stack
int __cdecl FUN_0033a6b0(const char* text, int count)
{
    int flags = 0;
    if (strchr(text, 'c')) flags |= 1;
    if (strchr(text, 'r')) flags |= 2;
    if (strchr(text, 'l')) flags |= 4;
    if (count > 0) flags |= 8;
    return flags;
}