class Base_252fc0 {
  public:
    virtual void f();
    Base_252fc0();
};
class SeqEventVarPosDist : public Base_252fc0 {
  public:
    virtual void g();
    int pad;
    float x;
    float y;
    SeqEventVarPosDist();
};
SeqEventVarPosDist::SeqEventVarPosDist() : Base_252fc0(), x(1.0f), y(100.0f) {}