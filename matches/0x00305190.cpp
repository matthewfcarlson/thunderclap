struct Ent_305190 {
    int a;
    int b;
    char c;
    unsigned char d;
    int x;
    int y;
};
struct Vec_305190 {
    int count;
    int cap;
    Ent_305190* data;
    void Grow(int n);
};
struct Sub_305190 {
    int F(int a, unsigned char b);
};
class T_305190 {
  public:
    char pad[0x20];
    Sub_305190* mSub;
    int pad2;
    Vec_305190 mVec;
    char pad3[0x71 - 0x34];
    char mFlag;
    void Add(int a, int b, int c, unsigned char d);
};
void T_305190::Add(int a, int b, int c, unsigned char d) {
    Vec_305190* v = &mVec;
    mFlag = 1;
    if (v->count >= v->cap)
        v->Grow(v->cap * 2);
    v->count++;
    Ent_305190* e = &v->data[v->count - 1];
    e->a = a;
    e->b = b;
    e->c = (char)c;
    e->d = d;
    if (mSub) {
        e->x = mSub->F(a, c);
        e->y = mSub->F(e->b, e->d);
    }
}
