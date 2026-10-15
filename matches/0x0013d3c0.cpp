class Caster {
  public:
    virtual void cast();
};
class Frame : public Caster {
  public:
    virtual void cast();
};
class Reached : public Caster {
  public:
    virtual void cast();
};
class Condition;
Condition* __cdecl find(const char*, Caster*);
class Factory {
  public:
    void add(Condition*);
};
void __cdecl init(Factory* factory) {
    {
        Frame frame;
        factory->add(find("frame", &frame));
    }
    {
        Reached reached;
        factory->add(find("frameReached", &reached));
    }
}