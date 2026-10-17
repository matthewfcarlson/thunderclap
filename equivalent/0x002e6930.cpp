// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6930 @ 0x002e6930
struct FILE_TYPE { char unused; };
extern FILE_TYPE DAT_004d9a30;
extern "C" int __cdecl _fwprintf(FILE_TYPE *, const char *);
extern "C" void __cdecl _longjmp(void *, int);
void __cdecl FUN_002e6930(void *jumpBuffer)
{
    _fwprintf(&DAT_004d9a30, "libpng error: %s\n");
    _longjmp(jumpBuffer, 1);
}