// STATUS: equivalent (tools/equiv.py level 3: 1006 inputs, branch coverage 9/10, incomplete)
// FUN_002619c0 @ 0x002619c0
struct Parser_2619c0 {
    char pad[0x2004];
    char *cursor;
};

char *__cdecl FUN_002611b0(Parser_2619c0 *p);

char *FUN_002619c0(Parser_2619c0 *p)
{
    char *start = p->cursor;
    p->cursor = start + 1;
    *start = 0;
    bool first = true;
    char *out = start;
    char *tok = FUN_002611b0(p);
    while (*tok != 0) {
        if (first) {
            first = false;
        } else {
            *out = ' ';
            out++;
        }
        while (*tok != 0) {
            *out = *tok;
            out++;
            tok++;
        }
        p->cursor = out + 1;
        tok = FUN_002611b0(p);
    }
    *out = 0;
    return start;
}
