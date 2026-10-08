class Obj { public: virtual void A(); virtual void B(); };
void Set(Obj **p, Obj *v) {
    if (v) v->A();
    if (*p) (*p)->B();
    *p = v;
}