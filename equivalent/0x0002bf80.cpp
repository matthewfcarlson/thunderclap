// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0002bf80 @ 0x0002bf80
// FUN_0002bf80 @ 0x0002bf80
struct Triple { unsigned a,b,c; }; struct Actor { int FUN_0002b970(unsigned, Triple, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); int FUN_0002bf80(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, unsigned h, unsigned i); }; int Actor::FUN_0002bf80(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, unsigned h, unsigned i) { Triple t = {b,c,d}; return FUN_0002b970(a,t,e,f,g,h,i,1); }
