class Item { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void q(); virtual void f(); virtual void g(); };
struct Arr { char x[16]; int count; char y[4]; Item **items; };
struct Context { void prepare(int); void process(int, Item *); };
struct Obj { char x[8]; Arr *arr; Context *ctx; char y[4]; int n; int run(); };
int Obj::run() {
 ctx->prepare(n);
 int i=0;
 if(n>0) do {
  Item *p;
  if(i<arr->count) p=arr->items[i]; else p=0;
  p->f();
  ctx->process(i,p);
  ++i;
 } while(i<n);
 return (int)ctx;
}