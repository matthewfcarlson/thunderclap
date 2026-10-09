class Base {
  public:
    virtual void f();
    Base();
};
class SeqEventVarPosDist : public Base {
  public:
    virtual void g();
    int pad;
    float x;
    float y;
    SeqEventVarPosDist();
};
SeqEventVarPosDist::SeqEventVarPosDist() : Base(), x(1.0f), y(100.0f) {}