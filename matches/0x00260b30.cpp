typedef unsigned int uint;
struct Parser { char pad[0x2008]; char* cursor; char* end; };
void __cdecl FUN_00260b30(Parser* p) {
    while (p->cursor < p->end) {
        if (*p->cursor != ' ') return;
        ++p->cursor;
    }
}