class CCollisionHitLocationCondition {};
class Caster {
  public:
    virtual void cast();
    Caster() {}
};
void __cdecl findCondition(void*, Caster*);
void __cdecl FUN_00054c30(void* p) {
    Caster c;
    findCondition(p, &c);
}
