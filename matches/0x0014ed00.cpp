struct TypeDesc {
    void* vf;
};
extern TypeDesc gSrcTD;
extern TypeDesc gDstTD;
extern "C" void* __cdecl RTDynamicCast(void* p, long vfDelta, TypeDesc* src, TypeDesc* dst, int throwErr);

class BattleObj {
  public:
    char pad[0x91];
    char mByte;
};

class FightObject {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual BattleObj* GetBattleObj();
};

class fight_Condition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    int mCond;
};

class fight_Param {
  public:
    virtual void pfunc_1();
    virtual void pfunc_2();
};

class CollisionDevastatorCondition : public fight_Condition, public fight_Param {
  public:
    virtual void dfunc_0();
    virtual void dfunc_1();
    virtual void dfunc_2();
    virtual bool vfunc_6(int a, FightObject* p, int c);
    char mByte;
};

bool CollisionDevastatorCondition::vfunc_6(int a, FightObject* p, int c) {
    if (RTDynamicCast(p, 0, &gSrcTD, &gDstTD, 0) == 0)
        return false;
    BattleObj* o = p->GetBattleObj();
    if (o == 0)
        return false;
    return mByte == o->mByte;
}
