class Target { char pad0[0x14]; int a; char pad1[0x0c]; int b; public: void run(int); };
void Target::run(int) { a = 4; b = 0; }