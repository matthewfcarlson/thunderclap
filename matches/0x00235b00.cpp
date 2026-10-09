struct Base {
    void Init(int);
};
struct Part {
    void Init();
};
struct FightNodeParentCondition {
    FightNodeParentCondition* Construct();
    char pad[0x20];
};
FightNodeParentCondition* FightNodeParentCondition::Construct() {
    ((Base*)this)->Init(0);
    *(int*)this = 0x427d14;
    *(int*)((char*)this + 0x0c) = 0;
    ((Part*)((char*)this + 0x10))->Init();
    *((char*)this + 0x1c) = 1;
    return this;
}