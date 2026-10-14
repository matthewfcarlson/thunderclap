extern int vt1_49820;
extern int vt2_49820;
class CSmartPropDistanceCondition {
  public:
    virtual void V0();
    char pad[0x18 - 4];
    class Part {
      public:
        void Init();
    } part;
    void Final();
    void Build();
};
void CSmartPropDistanceCondition::Build() {
    *(int*)this = (int)&vt1_49820;
    part.Init();
    *(int*)this = (int)&vt2_49820;
    Final();
}
