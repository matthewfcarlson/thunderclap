// STATUS: equivalent (tools/equiv.py level 3: 2972 inputs, branch coverage 4/4)
// FUN_00215b00 @ 0x00215b00
struct Record { int type; int value; };
struct Context {
    char reserved[8];
    Record* cursor;
    char reserved2[8];
    Record** source;
    Record* end;
};
int __cdecl FUN_00219430(Context*, const char*, int);
void __cdecl FUN_00215460(Context*, int);
// equiv-conv: FUN_00215b00 esi edx
int FUN_00215b00(Context* self, const char* text) {
    Record* output = *self->source;
    self->cursor = output;
    const char* p = text;
    while (*p) ++p;
    output->value = FUN_00219430(self, text, (int)(p - text));
    output->type = 4;
    if ((char*)self->end - (char*)self->cursor <= 8)
        FUN_00215460(self, 1);
    self->cursor = (Record*)((char*)self->cursor + 8);
    return 1;
}