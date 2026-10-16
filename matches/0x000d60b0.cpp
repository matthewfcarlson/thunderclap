#include "gen/global.h"

class MessageOverlay_d60b0 {
  public:
    void Method(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
};

template <> void Closure7<MessageOverlay, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char ** a = (const char **)__p1;

    const char* first = *a;
    const char* b = *++a;
    const char* c = *++a;
    const char* d = *++a;
    const char* e = *++a;
    const char* f = *++a;
    const char* g = *++a;
    ((*(MessageOverlay_d60b0 * *)&this->f_20)->*(*(void (MessageOverlay_d60b0::**)(const char *, const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(first, b, c, d, e, f, g);
}
