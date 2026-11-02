class ConditionFactoryCaster_13d3c0 {
  public:
    virtual void cast();
};
class ConditionFactoryCasterTemplate_13d3c0 : public ConditionFactoryCaster_13d3c0 {
  public:
    virtual void cast();
};
class Reached : public ConditionFactoryCaster_13d3c0 {
  public:
    virtual void cast();
};
class Condition;
extern "C" Condition* __cdecl FUN_002343e0(const char*, ConditionFactoryCaster_13d3c0*);
class Factory {
  public:
    void add(Condition*);
};
extern "C" void __cdecl FUN_0013d3c0(Factory* factory) {
    {
        ConditionFactoryCasterTemplate_13d3c0 frame;
        factory->add(FUN_002343e0("frame", &frame));
    }
    {
        Reached reached;
        factory->add(FUN_002343e0("frameReached", &reached));
    }
}