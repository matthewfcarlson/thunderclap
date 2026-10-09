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
    *(void**)this = (void*)0x3f719c;
    m.Inner::Inner();
    *(void**)this = (void*)0x3f6d50;
    ((CCondition*)this)->Finish();
}
