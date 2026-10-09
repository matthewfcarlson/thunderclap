struct Ent {
    int a;
    int b;
    char c;
    unsigned char d;
    int x;
    int y;
};
struct Vec {
    int count;
    int cap;
    Ent* data;
    void Grow(int n);
};
struct Sub {
    int F(int a, unsigned char b);
};
class T {
  public:
    char pad[0x20];
    Sub* mSub;
    int pad2;
    Vec mVec;
    char pad3[0x71 - 0x34];
    char mFlag;
    void Add(int a, int b, int c, unsigned char d);
};
void T::Add(int a, int b, int c, unsigned char d) {
    Vec* v = &mVec;
    mFlag = 1;
    if (v->count >= v->cap)
        v->Grow(v->cap * 2);
    v->count++;
    Ent* e = &v->data[v->count - 1];
    e->a = a;
    e->b = b;
    e->c = (char)c;
    e->d = d;
    if (mSub) {
        e->x = mSub->F(a, c);
        e->y = mSub->F(e->b, e->d);
    }
}
