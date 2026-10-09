class Inner { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual int Get(); };
class Outer { public: char pad0[4]; Inner* inner; char pad8[12]; int value; bool target(void** out1, int** out2); };
bool Outer::target(void** out1, int** out2) {
    if (inner->Get() == 4) {
        *out2 = (int*)value;
        *out1 = inner;
        return true;
    }
    return false;
}