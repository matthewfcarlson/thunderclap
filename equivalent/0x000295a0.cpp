// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 12/12)
// FUN_000295a0 @ 0x000295a0
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
void __cdecl FUN_00096d50(char *buf, int size, int a, int b);
extern char DAT_004dc168[0x100];

struct Text_295a0 {
    char pad[8];
    int a;
    int b;
    const char *FUN_00036d00();
};

struct Param {
    char pad[8];
    Text_295a0 *text;
    int type;
};

struct Pawn_295a0 {
    char pad[0x328];
    Param *param;
};

struct Group_295a0 {
    Pawn_295a0 *FUN_00024280(unsigned __int64 key);
    const char *FUN_000295a0(const char *name);
};

const char *Group_295a0::FUN_000295a0(const char *name)
{
    Pawn_295a0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return 0;
    Param *param = pawn->param;
    if (param) {
        if (param->type == 1) {
            if (param->text)
                return param->text->FUN_00036d00();
        } else if (param->type == 5) {
            Text_295a0 *text = param->text;
            if (text) {
                FUN_00096d50(DAT_004dc168, 0x100, text->a, text->b);
                return DAT_004dc168;
            }
        }
    }
    return "";
}
