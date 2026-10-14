// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 12/12)
// FUN_001d0e00 @ 0x001d0e00
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct lua_State;

struct lua_Debug {
    int word0;
    int word4;
    const char *what;       // 8
    int word0c;
    int value;              // 0x10
    char rest[0x60 - 0x14];
};

int __cdecl FUN_00213fc0(lua_State *L, int level, lua_Debug *ar);
int __cdecl FUN_00214bd0(lua_State *L, const char *options, lua_Debug *ar);

// Walks the call stack; frames whose first "what" letter is not f, g, l or t get value cleared.
void FUN_001d0e00(lua_State *L)
{
    struct Frame {
        lua_Debug ar;
        unsigned int cookie;
    } f;
    f.cookie = DAT_004d9968;

    int level = 1;
    while (FUN_00213fc0(L, level, &f.ar)) {
        if (FUN_00214bd0(L, "Snl", &f.ar)) {
            switch (*f.ar.what) {
            case 'f':
            case 'g':
            case 'l':
            case 't':
                break;
            default:
                f.ar.value = 0;
                break;
            }
        }
        level++;
    }
    __security_check_cookie(f.cookie);
}
