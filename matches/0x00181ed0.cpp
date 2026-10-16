#include "gen/hulkfight.h"

class Model_181ed0 {
  public:
    char pad[0x128];
    void* field;
    void Update(unsigned char);
    void Apply(void*, void*);
};
class Actor_181ed0 {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    Actor_181ed0* Get();
    Model_181ed0* ModelFor();
};
struct Vec_181ed0 {
    int a, b, c;
};

bool hulkfight::motion::PropActorThinkingAction::vfunc_3(int a, int b) {
    Actor_181ed0* x = (*(Actor_181ed0 * *)&this->f_20);
    Actor_181ed0* y = x->Get();
    Model_181ed0* m = y->ModelFor();
    unsigned char v = *((unsigned char*)(*(Actor_181ed0 * *)&this->f_1c) + 0x10);
    m->Update(v);
    if (!v) {
        void* p = *((void**)((char*)m + 0x128));
        if (p) {
            void* q = (*(Actor_181ed0 * *)&this->f_20)->D();
            if (q) {
                Vec_181ed0 t = *((Vec_181ed0*)((char*)q + 0x38));
                ((Model_181ed0*)p)->Apply(&t, (char*)q + 8);
            }
        }
    }
    return true;
}
