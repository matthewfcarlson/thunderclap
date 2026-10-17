// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002220d0 @ 0x002220d0
struct Result { char data[12]; };
extern float DAT_004c9d60;
void __cdecl FUN_00224f10(Result *);
struct Sub { char data[16]; void FUN_0022b4d0(float *, Result *); };
struct Obj { char pad[0x40]; Sub sub; int mode; void FUN_002220d0(); void FUN_0022c3b0(float *, Result *); };
void Obj::FUN_002220d0() {
    Result result;
    if (mode == 0 || mode == 2) FUN_0022c3b0(&DAT_004c9d60, &result);
    else if (mode == 1) sub.FUN_0022b4d0(&DAT_004c9d60, &result);
    FUN_00224f10(&result);
}