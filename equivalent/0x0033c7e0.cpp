// STATUS: equivalent (tools/equiv.py level 3: 20158 inputs, branch coverage 56/57, incomplete)
// FUN_0033c7e0 @ 0x0033c7e0
// FUN_0033c7e0 @ 0x0033c7e0
extern "C" int isdigit(int c);

struct MatchState_33c7e0 {
    const char *src_init;
    const char *src_end;
    void *L;
    int level;
    struct {
        const char *init;
        int len;
    } capture[32];
};

int FUN_00338e20(void *L, const char *fmt, ...);

// equiv-conv: FUN_0033c790 eax ecx ebx
const char *FUN_0033c790(int l, MatchState_33c7e0 *ms, const char *s);
// equiv-conv: FUN_0033c2b0 edi eax
const char *FUN_0033c2b0(MatchState_33c7e0 *ms, const char *p);
// equiv-conv: FUN_0033c430 ebx eax stack
int FUN_0033c430(int c, const char *p, const char *ec);
// equiv-conv: FUN_0033c520 eax ecx ebx
const char *FUN_0033c520(const char *p, const char *s, MatchState_33c7e0 *ms);
// equiv-conv: FUN_0033c320 eax edi
int FUN_0033c320(int c, int cl);
// equiv-conv: FUN_0033c6e0 esi ebx stack stack
const char *FUN_0033c6e0(MatchState_33c7e0 *ms, const char *s, const char *p, int what);
// equiv-conv: FUN_0033c730 esi ebx stack
const char *FUN_0033c730(MatchState_33c7e0 *ms, const char *s, const char *p);
// equiv-conv: FUN_0033c590 eax stack stack stack
const char *FUN_0033c590(const char *p, MatchState_33c7e0 *ms, const char *s, const char *ep);
// equiv-conv: FUN_0033c640 eax stack stack stack
const char *FUN_0033c640(const char *s, MatchState_33c7e0 *ms, const char *p, const char *ep);

const char *FUN_0033c7e0(MatchState_33c7e0 *ms, const char *s, const char *p)
{
    for (;;) {
        bool deflt = false;
        switch (*p) {
        case '(':
            if (p[1] == ')')
                return FUN_0033c6e0(ms, s, p + 2, -2);
            return FUN_0033c6e0(ms, s, p + 1, -1);
        case ')':
            return FUN_0033c730(ms, s, p + 1);
        case '%':
            if (p[1] == 'b') {
                s = FUN_0033c520(p + 2, s, ms);
                if (s == 0)
                    return 0;
                p += 4;
                continue;
            }
            if (p[1] == 'f') {
                p += 2;
                if (*p != '[')
                    FUN_00338e20(ms->L, "missing `[' after `%%f' in pattern");
                const char *ep = FUN_0033c2b0(ms, p);
                char previous = (s == ms->src_init) ? 0 : s[-1];
                if (FUN_0033c430((unsigned char)previous, p, ep - 1))
                    return 0;
                if (!FUN_0033c430((unsigned char)*s, p, ep - 1))
                    return 0;
                p = ep;
                continue;
            }
            if (isdigit((unsigned char)p[1])) {
                s = FUN_0033c790(p[1], ms, s);
                if (s == 0)
                    return 0;
                p += 2;
                continue;
            }
            deflt = true;
            break;
        case 0:
            return s;
        case '$':
            if (p[1] == 0)
                return (s == ms->src_end) ? s : 0;
            deflt = true;
            break;
        default:
            deflt = true;
            break;
        }
        if (deflt) {
            const char *ep = FUN_0033c2b0(ms, p);
            int m = 0;
            if (s < ms->src_end) {
                int c = (unsigned char)*s;
                if (*p == '%')
                    m = FUN_0033c320(c, p[1]);
                else if (*p == '.')
                    m = 1;
                else if (*p == '[')
                    m = FUN_0033c430(c, p, ep - 1);
                else
                    m = ((unsigned char)*p == c);
            }
            switch (*ep) {
            case '?':
                if (m) {
                    const char *res = FUN_0033c7e0(ms, s + 1, ep + 1);
                    if (res != 0)
                        return res;
                }
                p = ep + 1;
                continue;
            case '*':
                return FUN_0033c590(p, ms, s, ep);
            case '+':
                if (!m)
                    return 0;
                return FUN_0033c590(p, ms, s + 1, ep);
            case '-':
                return FUN_0033c640(s, ms, p, ep);
            default:
                if (!m)
                    return 0;
                s++;
                p = ep;
                continue;
            }
        }
    }
}
