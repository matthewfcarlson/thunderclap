typedef unsigned int uint;
struct Parser_260b30 {
    char pad[0x2008];
    char* cursor;
    char* end;
};
void __cdecl FUN_00260b30(Parser_260b30* p) {
    while (p->cursor < p->end) {
        if (*p->cursor != ' ')
            return;
        ++p->cursor;
    }
}