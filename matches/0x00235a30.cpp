class Base_235a30 {
  public:
    Base_235a30(int);
    virtual void V();
};
class Elem_235a30 {
  public:
    void Init();
};
class FightNodeCondition : public Base_235a30 {
  public:
    char pad04[8];
    int field0c;
    char pad10[4];
    FightNodeCondition();
    virtual void V2();
};
FightNodeCondition::FightNodeCondition() : Base_235a30(0) {
    field0c = 0;
    ((Elem_235a30*)((char*)this + 0x10))->Init();
}
