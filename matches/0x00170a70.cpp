class Root {
  public:
    Root();
    virtual void fn();
    int a;
    int flag;
    void* p;
    float x;
    void* q;
    float y;
    void* r;
};
class Track : public Root {
  public:
    Track();
    virtual void fn();
};
Track::Track() {
    p = 0;
    q = 0;
    r = 0;
    x = -1.0f;
    y = 100.0f;
    flag = 1;
}