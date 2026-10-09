struct Data { int a; int flag; int pad; int b; int c; int d; int e; int f; int g; int h; };
class Source { public: Data* Get(int); };
class Obj { char pad[0x54]; public: unsigned char active; char pad2[15]; int x; int y; int z; void Do(int p, Source* q); };
void Obj::Do(int p, Source* q) {
 Data* d=q->Get(p);
 if (d->flag == 0) { active=0; x=d->e; y=d->f; z=d->g; }
 else { active=1; x=d->b; y=d->c; z=d->d; }
}