class Inner { public: virtual void v0(); virtual bool Test(int); };
class Target { public: char pad[4]; Inner* obj; char pad2[0x824-8]; int state; bool Run(int x); };
bool Target::Run(int x) { if (obj->Test(x)) { state = 1; return true; } state = 0; return false; }