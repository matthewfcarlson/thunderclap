// STATUS: equivalent (tools/equiv.py level 3: 13637 inputs, branch coverage 40/40)
// FUN_002337c0 @ 0x002337c0
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"

class Lexer {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual char HasToken();
    virtual __int64 TokenType();
    void FUN_00232c90();
};

class Branch_2337c0;

class Handler_2337c0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void Parse(int a0, Lexer *lexer, int index);
    char pad04[0x10];
    Branch_2337c0 *parent;
};

struct NodeCtorA { Handler_2337c0 *FUN_0023c620(); };
struct Node_nv_2337c0 {
    Handler_2337c0 *FUN_00231940();
};
struct Store_nv_2337c0 {
    Handler_2337c0 *FUN_0023c500();
};
struct Reference_nv_2337c0 {
    Handler_2337c0 *FUN_0023c2c0();
};

struct ScopeNode {
    char pad0[0x20];
    ScopeNode *next;
};

extern "C" int FUN_00238190(int mode);
extern "C" int FUN_00266da0(hulk_intptr v);
extern "C" void FUN_00232cc0(Lexer *lexer, const char *msg);
void *__cdecl FUN_00263ea0(unsigned int size);

class Branch_2337c0 {
public:
    char pad0[0x1c];
    ScopeNode *scopes;
    char ParseBlock(int a0, Lexer *lexer, int index);
};

char Branch_2337c0::ParseBlock(int a0, Lexer *lexer, int index)
{
    int saved = FUN_00266da0(FUN_00238190(2));

    while (lexer->HasToken()) {
        int depth = 0;
        for (ScopeNode *n = scopes; n != 0; n = n->next)
            depth++;

        Handler_2337c0 *h = 0;
        void *mem;
        bool known = true;
        if (lexer->TokenType() == DAT_004e5b30) {
            mem = FUN_00263ea0(0x28);
            if (mem)
                h = ((NodeCtorA *)mem)->FUN_0023c620();
        } else if (lexer->TokenType() == DAT_004e5b70) {
            mem = FUN_00263ea0(0x30);
            if (mem)
                h = ((Node_nv_2337c0*)(((fight::Node*)(((fight::Node *)mem)))))->FUN_00231940();
        } else if (lexer->TokenType() == (*(__int64*)&DAT_004e5ba8)) {
            mem = FUN_00263ea0(0x28);
            if (mem)
                h = ((Store_nv_2337c0*)(((fight::Store*)(((fight::Store *)mem)))))->FUN_0023c500();
        } else if (lexer->TokenType() == (*(__int64*)&DAT_004e5b10)) {
            mem = FUN_00263ea0(0x38);
            if (mem)
                h = ((Reference_nv_2337c0*)(((fight::Reference*)(((fight::Reference *)mem)))))->FUN_0023c2c0();
        } else {
            FUN_00232cc0(lexer, "Unexpected token.");
            lexer->FUN_00232c90();
            known = false;
        }
        if (known) {
            h->AddRef();
            h->parent = this;
            h->Parse(a0, lexer, index);
            h->Release();
        }
        int depth2 = 0;
        for (ScopeNode *n = scopes; n != 0; n = n->next)
            depth2++;
        if (depth2 > depth && index >= 0)
            index++;
    }

    FUN_00266da0(saved);
    return 1;
}
