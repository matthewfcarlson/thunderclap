class Sub_1ab730 {
  public:
    void Init();
};
class Event_CharacterTemplateVariationCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int);
    virtual void vfunc_6();
    char pad[0x14];
    Sub_1ab730 sub;
    Event_CharacterTemplateVariationCondition(int);
    void Finish();
};
void __cdecl FUN_00267090(Event_CharacterTemplateVariationCondition*);
Event_CharacterTemplateVariationCondition::Event_CharacterTemplateVariationCondition(int flag) {
    sub.Init();
    Finish();
    if (flag & 1)
        FUN_00267090(this);
}
