// STATUS: equivalent (tools/equiv.py level 3: 3095 inputs, branch coverage 41/42, incomplete)
// luaK_posfix: finish a binary operator (and / or merge jump lists, concat merges OP_CONCATs, the rest codebinop).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
// equiv-conv: FUN_00221860 eax ecx edx edi stack
extern "C" void __cdecl FUN_00221860(int rkc, int rkb, int op, LuaVMExpDesc* res, LuaVMFuncState* fs);

extern "C" void __cdecl FUN_002218d0(LuaVMFuncState* fs, int op, LuaVMExpDesc* e1, LuaVMExpDesc* e2) {
    if (op == 5) {
        if (e2->t != e2->f)
            FUN_00221190(fs, e2);
        else
            FUN_00220d90(fs, e2);
        if (e2->k == 0xa) {
            LuaVMProto* f = fs->f;
            if ((f->code[e2->info] & 0x3f) == 0x13) {
                if (e1->k == 0xb) {
                    if (e1->info >= (int)fs->nactvar && e1->info < 0xfa)
                        fs->freereg--;
                }
                LuaVMInstruction* code = f->code;
                LuaVMInstruction old = code[e2->info];
                code[e2->info] = old ^ (((unsigned int)e1->info << 15 ^ old) & 0xff8000);
                e1->k = e2->k;
                e1->info = e2->info;
                return;
            }
        }
        FUN_00221110(fs, e2);
        if (e2->k == 0xb) {
            if (e2->info >= (int)fs->nactvar && e2->info < 0xfa)
                fs->freereg--;
        }
        if (e1->k == 0xb) {
            if (e1->info >= (int)fs->nactvar && e1->info < 0xfa)
                fs->freereg--;
        }
        e1->info = FUN_00220b20(fs, (LuaVMInstruction)(((e1->info << 9 | e2->info) << 6) | 0x13), fs->ls->lastline);
        e1->k = 0xa;
        return;
    }
    if (op == 12) {
        FUN_00220d90(fs, e2);
        FUN_002207c0(fs, &e1->f, e2->f);
        e1->k = e2->k;
        e1->info = e2->info;
        e1->aux = e2->aux;
        e1->t = e2->t;
        return;
    }
    if (op == 13) {
        FUN_00220d90(fs, e2);
        FUN_002207c0(fs, &e1->t, e2->t);
        e1->k = e2->k;
        e1->info = e2->info;
        e1->aux = e2->aux;
        e1->f = e2->f;
        return;
    }
    int rkb = FUN_00221200(fs, e1);
    int rkc = FUN_00221200(fs, e2);
    if (e2->k == 0xb) {
        if (e2->info >= (int)fs->nactvar && e2->info < 0xfa)
            fs->freereg--;
    }
    if (e1->k == 0xb) {
        if (e1->info >= (int)fs->nactvar && e1->info < 0xfa)
            fs->freereg--;
    }
    FUN_00221860(rkc, rkb, op, e1, fs);
}
