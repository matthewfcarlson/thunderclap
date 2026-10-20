// Same code shape as 0x0004a030 (propagated; names are from that function)
extern int vtableA;
extern int vtableB;
class Part_4a110 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CGrappleCharacterTemplateCondition_4a110 : public CCondition {
  public:
    char pad[12];
    Part_4a110 part;
    void Run();
    void Finish();
};
void CGrappleCharacterTemplateCondition_4a110::Run() {
    *(int*)this = (int)&vtableA;
    part.Init();
    *(int*)this = (int)&vtableB;
    Finish();
}