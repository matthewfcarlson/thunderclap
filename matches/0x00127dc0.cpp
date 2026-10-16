namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
class TargetCaster : public ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int g1, g2;
bool fight::TargetCaster::Check(void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}