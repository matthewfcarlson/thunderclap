// Negative: calling the other virtual slot is not the same call.
// ref-msvc
// expect: unmatched=2
struct B { virtual float get(); virtual float get2(); };
extern "C" float ref(B* b) { return b->get() * 2.0f + b->get2(); }
extern "C" float test(B* b) { return b->get2() * 2.0f + b->get(); }
