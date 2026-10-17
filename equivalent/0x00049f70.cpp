// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 14/14)
// CCharacterTemplateCondition::vfunc_7 @ 0x00049f70
struct CharacterTemplate { unsigned __int64 FUN_000443c0(); };
struct CharacterData { char pad[0x11c]; CharacterTemplate* characterTemplate; };
struct CharacterState { CharacterData* FUN_00059a30(); };
struct ConditionContext { CharacterState* FUN_000592a0(); };
struct CCharacterTemplateCondition {
    void* vtable;
    char pad[8];
    int comparison;
    unsigned int templateLow;
    unsigned int templateHigh;
    bool vfunc_7(ConditionContext* context);
};
bool CCharacterTemplateCondition::vfunc_7(ConditionContext* context) {
    CharacterData* data = context->FUN_000592a0()->FUN_00059a30();
    unsigned __int64 templateId = data->characterTemplate ? data->characterTemplate->FUN_000443c0() : 0;
    bool same = (unsigned int)templateId == templateLow && (unsigned int)(templateId >> 32) == templateHigh;
    if (comparison == 0) return same;
    if (comparison == 1) return !same;
    return false;
}