typedef unsigned int U;
class C { public: void F(U,U); void A(U); void B(U); void D(U); };
void C::F(U a,U b) { A(b); B(b); D(b); }