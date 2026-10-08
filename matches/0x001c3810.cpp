class C { public: char pad[0x14]; C* p; void target(int,int,int,int); void helper(int,int,int,int); };
void C::target(int a,int b,int c,int d) { C* q=p; if(q) q->helper(a,b,c,d); }