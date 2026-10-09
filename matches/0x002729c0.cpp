class Inner { public: virtual void First(); virtual void Second(); };
class Target { public: char pad[0x0c]; Inner inner; char pad2[0x30]; int value40; int value44; void run(int); };
void Target::run(int x) { inner.First(); value44=x; value40=0; inner.Second(); }