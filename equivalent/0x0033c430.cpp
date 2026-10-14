// STATUS: equivalent (tools/equiv.py level 3: 327 inputs, branch coverage 21/22, incomplete)
// FUN_0033c430 @ 0x0033c430
// Lua 5.0 lstrlib matchbracketclass
// equiv-conv: FUN_0033c320 eax edi
int FUN_0033c320(int c, int cl);

// equiv-conv: FUN_0033c430 ebx eax stack
int FUN_0033c430(int c, const char *p, const char *ec)
{
    int sig = 1;
    if (*(p + 1) == '^') {
        sig = 0;
        p++;
    }
    while (++p < ec) {
        if (*p == '%') {
            p++;
            if (FUN_0033c320(c, *p))
                return sig;
        } else if (*(p + 1) == '-' && (p + 2 < ec)) {
            p += 2;
            if ((unsigned char)*(p - 2) <= c && c <= (unsigned char)*p)
                return sig;
        } else if ((unsigned char)*p == c) {
            return sig;
        }
    }
    return !sig;
}
