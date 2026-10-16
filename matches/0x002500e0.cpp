class Base {
  public:
    virtual void V();
    Base();
    int x;
};
class Part {
  public:
    void Init(const char*, int);
};
class audio_SeqEventWait : public Base {
  public:
    Part part;
    audio_SeqEventWait();
    virtual void V();
};
audio_SeqEventWait::audio_SeqEventWait() {
    part.Init("($= $myvar true)", 2);
}