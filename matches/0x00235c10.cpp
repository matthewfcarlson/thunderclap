extern "C" char DAT_00427d38[];
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
    *(int*)this = ((int)DAT_00427d38);
    y = 0;
    z = 0;
}