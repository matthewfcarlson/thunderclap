// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_HULKFIGHT_H
#define TREE_GAME_HULKFIGHT_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern "C" void FUN_00234810(void*, void*);
extern char DAT_0049850c;
TREE_TU_END
void operator delete(void*);
void* __cdecl operator new(size_t size);
TREE_TU_BEGIN
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
TREE_TU_END
#endif
