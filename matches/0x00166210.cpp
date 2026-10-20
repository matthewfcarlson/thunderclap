// Same code shape as 0x0011c270 (propagated; names are from that function)
void __cdecl Cleanup(int);
class TargetCharacterTemplateCondition_166210 {
  public:
    int a, b;
    virtual ~TargetCharacterTemplateCondition_166210();
    int d;
    virtual void hulk_slot_F(); void F();
};
TargetCharacterTemplateCondition_166210::~TargetCharacterTemplateCondition_166210() {
    Cleanup(d);
    F();
}