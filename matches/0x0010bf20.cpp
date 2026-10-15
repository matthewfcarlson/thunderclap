class Caster {
  public:
    virtual void f();
};
class TargetCaster : public Caster {};
class MotionCaster : public Caster {};
extern int __cdecl lookup(const char*, Caster*);
class Factory {
  public:
    void add(int);
};
void setup(Factory* p) {
    {
        TargetCaster a;
        p->add(lookup("faceTarget", &a));
    }
    {
        MotionCaster b;
        p->add(lookup("faceMotion", &b));
    }
}