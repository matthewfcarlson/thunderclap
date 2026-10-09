extern const float zeroValue;
class Item { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual bool Check(); };
struct Entry { Item *obj; float value; char flag; char pad[31]; };
class Owner { public: char pad[0x68]; unsigned count; Entry entries[1]; int target(int index); };
int Owner::target(int index) {
 int found=0;
 for (unsigned i=0;i<count;++i) { Entry *e=&entries[i]; if (!e->obj->Check() && (e->value >= zeroValue || e->flag)) { if(index==found) return (int)e->obj; ++found; } }
 return 0;
}