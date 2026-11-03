#include "gen/owners.h"
class Path_262700 {
  public:
    unsigned int Length();
    void SetLength(unsigned int);
    char* Data();
    void Finish();
};
struct Temp_262700 {
    char pad[12];
};
extern "C" Path_262700* FUN_00262700(Path_262700* self, Path_262700* other) {
    unsigned int n = self->Length();
    if (n > 0) {
        char* s = ((owners::String_23fbb0 *)self)->FUN_0023fbb0();
        char c = s[n - 1];
        if (c == '\\' || c == '/') {
            s[n - 1] = 0;
            --n;
            self->SetLength(n);
        }
    }
    unsigned int m = other->Length();
    if (m > 0) {
        char* p = self->Data();
        char c = *p;
        if (c != '\\' && c != '/') {
            if (self->Length() > 0) {
                Temp_262700 t;
                char* x = ((char *)((owners::String_23fc40 *)&t)->FUN_0023fc40("\\", (hulk_intptr)0));
                ((owners::String_23ff50 *)self)->FUN_0023ff50((owners::String_23ff50 *)x);
                ((owners::Str_240060 *)&t)->FUN_00240060();
            }
        }
        ((owners::String_23ff50 *)self)->FUN_0023ff50((owners::String_23ff50 *)(Path_262700 *)other);
    }
    return self;
}