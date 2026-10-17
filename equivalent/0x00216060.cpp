// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_00216060 @ 0x00216060
struct Entry { int type; int value; };
struct Buffer { char pad[8]; Entry *cursor; char pad2[12]; Entry *end; };
int __cdecl FUN_00219430(Buffer *, const char *, int);
void __cdecl FUN_00215460(Buffer *, int);
// equiv-conv: FUN_00216060 esi edx
void FUN_00216060(Buffer *buffer, const char *text)
{
    const char *p = text;
    while (*p) ++p;
    Entry *entry = buffer->cursor;
    entry->value = FUN_00219430(buffer, text, (int)(p - text));
    entry->type = 4;
    if ((char *)buffer->end - (char *)buffer->cursor <= 8)
        FUN_00215460(buffer, 1);
    buffer->cursor = (Entry *)((char *)buffer->cursor + 8);
}