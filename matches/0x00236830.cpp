// Same code shape as 0x00236820 (propagated; names are from that function)
class Obj { public: void A(); void B(); void Target(); };
void Obj::Target() { A(); B(); }