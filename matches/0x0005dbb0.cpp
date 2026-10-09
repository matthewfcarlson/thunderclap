struct A { void f(); };
struct COpportunityBallTrack { unsigned vp; char a[0x18-4]; A x; char b[0x34-0x19]; A y; char c[0x40-0x35]; A z; void init(); void base(); };
void COpportunityBallTrack::init() { vp = 0x3fa248; z.f(); y.f(); x.f(); base(); }
