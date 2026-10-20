#include "compat/ptr.h"
struct Obj_2135a0 {
    char pad[8];
    int offset;
};
typedef unsigned int size_t;
extern "C" size_t strlen(const char*);
extern "C" int __fastcall find(int, Obj_2135a0*);
extern "C" int make(Obj_2135a0*, const char*, hulk_intptr);
extern "C" void emit(Obj_2135a0*, int, int*, int);
void target(Obj_2135a0* obj, int type, const char* str) {
    int tmp[2];
    int id = find(type, obj);
    tmp[1] = make(obj, str, strlen(str));
    tmp[0] = 4;
    emit(obj, id, tmp, obj->offset);
    obj->offset += 8;
}