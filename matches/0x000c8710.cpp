// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj { public: virtual void A(); virtual void B(); };
void Set(Obj **p, Obj *v) {
    if (v) v->A();
    if (*p) (*p)->B();
    *p = v;
}