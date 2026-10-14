// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 20/22, incomplete)
// FUN_00260b60 @ 0x00260b60
struct Parser {
    char pad0[0x2008];
    const char* cur;    // 0x2008
    const char* end;    // 0x200c
};

// Skips leading spaces, then advances past one space-delimited token; a parenthesised group
// counts as part of the token and is consumed through its closing parenthesis.
void FUN_00260b60(Parser* p)
{
    while (p->cur < p->end && *p->cur == ' ')
        p->cur++;
    int depth = 0;
    while (p->cur < p->end) {
        char c = *p->cur;
        if (c == '(') {
            depth++;
        } else if (c == ')') {
            if (depth == 0)
                return;
            if (--depth == 0) {
                p->cur++;
                return;
            }
        } else if (c == ' ' && depth == 0) {
            return;
        }
        p->cur++;
    }
}
