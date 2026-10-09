class Item { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
class List { public: char pad0[0x10]; int count; char pad14[4]; Item **items; void init(int); void process(int, Item*); };
class Obj { public: char pad0[4]; List *data; char pad8[4]; List *list; int n; int run(); };
int Obj::run() { list->init(n); int i=0; if(n>0) { do { Item *x; if(i<data->count) x=data->items[i]; else x=0; x->f6(); list->process(i,x); ++i; } while(i<n); } return (int)list; }