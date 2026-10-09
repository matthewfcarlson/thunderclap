class Item { public:
 virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(int,int,int,int); virtual void l(); virtual void m(); virtual void n(); virtual void o( void* ); virtual void p(); virtual void q(); virtual void r(); virtual void s(); };
class BranchNode { char pad[0x18]; public: int count; Item **items; void vfunc_18(Item *); };
void BranchNode::vfunc_18(Item *item) {
 if (item) {
  Item **slot = items + count;
  item->a();
  Item *old = *slot;
  if (old) old->b();
  *slot = item;
  ++count;
  item->o(this);
  item->k(1,2,1,1);
  item->k(1,6,2,1);
 }
}