class Base {
  public:
    Base(int);
    virtual void V();
};
class Elem {
  public:
    void Init();
};
class FightNodeCondition : public Base {
  public:
    char pad04[8];
    int field0c;
    char pad10[4];
    FightNodeCondition();
    virtual void V2();
};
FightNodeCondition::FightNodeCondition() : Base(0) {
    field0c = 0;
    ((Elem*)((char*)this + 0x10))->Init();
}
