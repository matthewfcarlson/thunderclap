extern "C" char DAT_00427d14[];
struct Base_235b00 {
    void Init(int);
};
struct Part_235b00 {
    void Init();
};
struct FightNodeParentCondition {
    FightNodeParentCondition* Construct();
    char pad[0x20];
};
FightNodeParentCondition* FightNodeParentCondition::Construct() {
    ((Base_235b00*)this)->Init(0);
    *(int*)this = ((int)DAT_00427d14);
    *(int*)((char*)this + 0x0c) = 0;
    ((Part_235b00*)((char*)this + 0x10))->Init();
    *((char*)this + 0x1c) = 1;
    return this;
}