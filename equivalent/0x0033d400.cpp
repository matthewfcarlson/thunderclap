// STATUS: equivalent (tools/equiv.py level 3: 123 inputs, branch coverage 29/30, incomplete)
// FUN_0033d400 @ 0x0033d400
extern "C" int __cdecl isdigit(int c);
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct lua_State;

struct luaL_Buffer_33d400 {
    char *p;
    int lvl;
    lua_State *L;
    char buffer[0x200];
};

const char *FUN_00339df0(lua_State *L, int arg, unsigned int *len);
void FUN_00339630(lua_State *L, luaL_Buffer_33d400 *b);
char *FUN_00339470(luaL_Buffer_33d400 *b);
// equiv-conv: FUN_0033d310 ebx stack stack stack
const char *FUN_0033d310(const char *fmt, lua_State *L, char *form, int *hasprecision);
double FUN_00339ec0(lua_State *L, int arg);
int FUN_00339f70(lua_State *L, int arg);
// equiv-conv: FUN_0033d1c0 ecx esi edx
void FUN_0033d1c0(int arg, luaL_Buffer_33d400 *b, lua_State *L);
void FUN_00212ed0(lua_State *L, int arg);
void FUN_00339590(luaL_Buffer_33d400 *b);
void FUN_003394b0(luaL_Buffer_33d400 *b, const char *s, unsigned int len);
void FUN_00339540(luaL_Buffer_33d400 *b);
int FUN_00338e20(lua_State *L, const char *fmt, ...);

struct Frame_33d400 {
    int unused;
    int hasprecision;
    const char *strfrmt_end;
    int arg;
    unsigned int sfl;
    unsigned int l;
    char form[20];
    luaL_Buffer_33d400 b;
    int gap;
    char buff[120];
};

int FUN_0033d400(lua_State *L)
{
    unsigned int cookie = DAT_004d9968;
    Frame_33d400 f;
    f.arg = 1;
    const char *strfrmt = FUN_00339df0(L, f.arg, &f.sfl);
    f.strfrmt_end = strfrmt + f.sfl;
    FUN_00339630(L, &f.b);
    while (strfrmt < f.strfrmt_end) {
        if (*strfrmt != '%') {
            if (f.b.p >= f.b.buffer + sizeof(f.b.buffer))
                FUN_00339470(&f.b);
            *f.b.p++ = *strfrmt++;
        } else if (*++strfrmt == '%') {
            if (f.b.p >= f.b.buffer + sizeof(f.b.buffer))
                FUN_00339470(&f.b);
            *f.b.p++ = *strfrmt++;
        } else {
            f.hasprecision = 0;
            if (isdigit((unsigned char)*strfrmt) && strfrmt[1] == '$') {
                int r = FUN_00338e20(L, "obsolete option (d$) to `format'");
                __security_check_cookie(cookie);
                return r;
            }
            f.arg++;
            strfrmt = FUN_0033d310(strfrmt, L, f.form, &f.hasprecision);
            switch (*strfrmt++) {
            case 'c':
            case 'd':
            case 'i':
                _sprintf(f.buff, f.form, FUN_00339f70(L, f.arg));
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                _sprintf(f.buff, f.form, (unsigned int)FUN_00339ec0(L, f.arg));
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                _sprintf(f.buff, f.form, FUN_00339ec0(L, f.arg));
                break;
            case 'q':
                FUN_0033d1c0(f.arg, &f.b, L);
                continue;
            case 's': {
                const char *s = FUN_00339df0(L, f.arg, &f.l);
                if (!f.hasprecision && f.l >= 100) {
                    FUN_00212ed0(L, f.arg);
                    FUN_00339590(&f.b);
                    continue;
                }
                _sprintf(f.buff, f.form, s);
                break;
            }
            default: {
                int r = FUN_00338e20(L, "invalid option to `format'");
                __security_check_cookie(cookie);
                return r;
            }
            }
            const char *e = f.buff;
            while (*e++ != 0) {
            }
            FUN_003394b0(&f.b, f.buff, (unsigned int)(e - 1 - f.buff));
        }
    }
    FUN_00339540(&f.b);
    __security_check_cookie(cookie);
    return 1;
}
