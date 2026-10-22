class SeqEvent_252fc0 {
  public:
    virtual void f();
    SeqEvent_252fc0();
};
class SeqEventVarPosDist : public SeqEvent_252fc0 {
  public:
    virtual void g();
    int pad;
    float x;
    float y;
    SeqEventVarPosDist();
};
SeqEventVarPosDist::SeqEventVarPosDist() : SeqEvent_252fc0(), x(1.0f), y(100.0f) {}