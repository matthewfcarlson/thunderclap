extern "C" char DAT_003f6d50[];
extern "C" char DAT_003f719c[];
class Inner {
  public:
    Inner();
};
class CCondition {
  public:
    void Finish();
};
class CSmartPropNameCondition {
  public:
    int pad[6];
    Inner m;
    void Fn();
};
void CSmartPropNameCondition::Fn() {
    *(void**)this = (void*)((int)DAT_003f719c);
    m.Inner::Inner();
    *(void**)this = (void*)((int)DAT_003f6d50);
    ((CCondition*)this)->Finish();
}
