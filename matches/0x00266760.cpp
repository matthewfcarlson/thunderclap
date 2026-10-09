class Thing { char pad[0x14]; public: int state; void Wait(); };
void thunk();
void step();
void Thing::Wait() { while (state != 3) { thunk(); step(); } }