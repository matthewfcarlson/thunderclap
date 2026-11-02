// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_00216060 @ 0x00216060
struct Entry { int type; int value; };
struct Buffer { char pad[8]; Entry *cursor; char pad2[12]; Entry *end; };
int __cdecl FUN_00219430(Buffer *, const char *, int);
extern "C" void __cdecl FUN_00215460(void *, int);
// equiv-conv: FUN_00216060 esi edx
extern "C" void FUN_00216060(void *buffer, const char *text)
{
    const char *p = text;
    while (*p) ++p;
    Entry *entry = ((Buffer *)buffer)->cursor;
    entry->value = FUN_00219430(((Buffer *)buffer), text, (int)(p - text));
    entry->type = 4;
    if ((char *)((Buffer *)buffer)->end - (char *)((Buffer *)buffer)->cursor <= 8)
        FUN_00215460((Buffer *)((Buffer *)buffer), 1);
    ((Buffer *)buffer)->cursor = (Entry *)((char *)((Buffer *)buffer)->cursor + 8);
}