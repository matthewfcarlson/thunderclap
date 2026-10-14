// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00217640 @ 0x00217640
// 0x00217640: Lua tostring conversion of a number value in place (lua_Number is a float here)
struct State;
struct TValue_217640 {
    int tt;
    union {
        float n;
        void* p;
        int i;
    } value;
};

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern int __cdecl _sprintf(char*, const char*, ...);
void* __cdecl FUN_00219430(State* L, const char* s, unsigned int len);

int FUN_00217640(State* L, TValue_217640* o)
{
    unsigned int cookie = DAT_004d9968;
    char buf[32];
    if (o->tt != 3) {
        __security_check_cookie(cookie);
        return 0;
    }
    _sprintf(buf, "%.7g", (double)o->value.n);
    const char* e = buf;
    while (*e != 0)
        e++;
    o->value.p = FUN_00219430(L, buf, (unsigned int)(e - buf));
    o->tt = 4;
    __security_check_cookie(cookie);
    return 1;
}
