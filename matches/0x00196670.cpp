class Ref_196670 {
  public:
    virtual void Free();
    virtual void Rel();
};
class Del_196670 {
  public:
    virtual void Dtor(int f);
};
class Base_196670 {
  public:
    virtual ~Base_196670() throw();
    int b[6];
};
namespace hulkfight {
namespace motion {
class FireBeamAction : public Base_196670 {
  public:
    virtual ~FireBeamAction() throw();
    int i1c;
    Ref_196670* r20;
    char pad[0x10];
    Ref_196670* r34;
    Ref_196670* r38;
    char pad2[0x10];
    Ref_196670* r4c;
    char pad3[0x14];
    Ref_196670* r64;
    Del_196670* r68;
};
} // namespace motion
} // namespace hulkfight
inline void Rl(Ref_196670*& r) {
    if (r) {
        r->Rel();
        r = 0;
    }
}
hulkfight::motion::FireBeamAction::~FireBeamAction() throw() {
    Rl(r38);
    Rl(r34);
    Rl(r20);
    Rl(r4c);
    if (i1c)
        i1c = 0;
    Rl(r64);
    if (r68)
        r68->Dtor(1);
}
