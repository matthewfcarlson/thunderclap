class Sub { public: void* Init(); };
class ImageLoader { public: void *v; int a; int b; int c; int d; int e; int f; };
extern "C" void * alloc(int);
void * __fastcall FUN_002c0c40(ImageLoader *p) {
 p->a=0;
 p->b=0x19001;
 p->c=0;
 p->d=0;
 p->v=(void*)0x42eb0c;
 p->f=0x20;
 Sub* s = (Sub*)alloc(0xa4);
 int r;
 if (s) r = (int)s->Init();
 else r = 0;
 p->e = r;
 return p;
}
