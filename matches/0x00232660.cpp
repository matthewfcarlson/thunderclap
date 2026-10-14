extern int gCount_232660;
extern int gMax_232660;

class Action {
  public:
    virtual ~Action();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    Action();
};

Action::Action() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    ++gCount_232660;
    if (gCount_232660 > gMax_232660)
        gMax_232660 = gCount_232660;
}