class Obj;
struct Sub {
    void reset(Obj*);
};
class Obj {
    char pad[0x40];
    Sub sub;
    char gap[0xf];
    int state;

  public:
    void work(int a, int b);
    void dispatch(int a, int b);
};
void Obj::dispatch(int a, int b) {
    switch (state) {
    case 0:
    case 2:
        work(a, b);
        break;
    case 1:
        sub.reset(this);
        state = 0;
        work(a, b);
        break;
    }
}