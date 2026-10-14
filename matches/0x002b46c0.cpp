struct Data_2b46c0 {
    int a;
    int flag;
    int pad;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};
class Source_2b46c0 {
  public:
    Data_2b46c0* Get(int);
};
class Obj_2b46c0 {
    char pad[0x54];

  public:
    unsigned char active;
    char pad2[15];
    int x;
    int y;
    int z;
    void Do(int p, Source_2b46c0* q);
};
void Obj_2b46c0::Do(int p, Source_2b46c0* q) {
    Data_2b46c0* d = q->Get(p);
    if (d->flag == 0) {
        active = 0;
        x = d->e;
        y = d->f;
        z = d->g;
    } else {
        active = 1;
        x = d->b;
        y = d->c;
        z = d->d;
    }
}