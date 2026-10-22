class SeqEvent_2500e0 {
  public:
    virtual void V();
    SeqEvent_2500e0();
    int x;
};
class Part {
  public:
    void Init(const char*, int);
};
class SeqEventWait_2500e0 : public SeqEvent_2500e0 {
  public:
    Part part;
    SeqEventWait_2500e0();
    virtual void V();
};
SeqEventWait_2500e0::SeqEventWait_2500e0() {
    part.Init("($= $myvar true)", 2);
}