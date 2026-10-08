extern float zero;
struct Receiver { void run(int,int,int); };
class OpportunityAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); char p0[0x24]; float value; char p1[4]; int arg3; char p2[4]; int selfarg; int arg2; int argx; int argy; char padtarget[4]; Receiver* target; };
void OpportunityAction::f4() { if (value < zero && target) target->run(selfarg, arg2, arg3); }