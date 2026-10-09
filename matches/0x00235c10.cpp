class Base {
  public:
    int x[3];
    Base(int);
};
class FightNodeTimeCondition : public Base {
  public:
    int y;
    int z;
    FightNodeTimeCondition();
};
FightNodeTimeCondition::FightNodeTimeCondition() : Base(0) {
    *(int*)this = 0x427d38;
    y = 0;
    z = 0;
}