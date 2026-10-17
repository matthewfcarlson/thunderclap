// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CCharacterBoolCondition::vfunc_7 @ 0x0004a7e0
struct Character;
struct Context {
    Character* FUN_000592a0();
};
struct Character {
    Character* FUN_00059a30();
};
typedef unsigned char (__fastcall *CharacterTest)(Character*);
struct CCharacterBoolCondition {
    char padding[12];
    CharacterTest test;
    int mode;
    unsigned char vfunc_7(Context* context);
};
unsigned char CCharacterBoolCondition::vfunc_7(Context* context) {
    Character* character = context->FUN_000592a0()->FUN_00059a30();
    unsigned char result = test(character);
    if (mode == 1) return result == 0;
    if (mode != 0) return 0;
    return result;
}