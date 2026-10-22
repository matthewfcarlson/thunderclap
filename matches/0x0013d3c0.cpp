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
Condition* __cdecl find(const char*, ConditionFactoryCaster_13d3c0*);
class Factory {
  public:
    void add(Condition*);
};
void __cdecl init(Factory* factory) {
    {
        ConditionFactoryCasterTemplate_13d3c0 frame;
        factory->add(find("frame", &frame));
    }
    {
        Reached reached;
        factory->add(find("frameReached", &reached));
    }
}