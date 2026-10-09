extern int vt1;
extern int vt2;
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
    *(int*)this = (int)&vt1;
    part.Init();
    *(int*)this = (int)&vt2;
    Final();
}
