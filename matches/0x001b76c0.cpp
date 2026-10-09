// Same code shape as 0x001b75d0 (propagated; names are from that function)
class Ref { public: virtual void F(); };
class Owner { public: Ref* mRef; Owner* Set(Ref* r); };
Owner* Owner::Set(Ref* r) { mRef = r; if (r) r->F(); return this; }