extern int gCount;
extern int gMax;

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
    ++gCount;
    if (gCount > gMax)
        gMax = gCount;
}