// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234090..0x002343b0 (kind game, layer engine, confidence high), dominant class fight::Param
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f53a6861 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f53a6861 {} using namespace fn_f53a6861;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f53a6861 {
class Reader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool HasMore();                                                  // slot 3
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void Read(int a, int b, char *buf, int size);                    // slot 8
    virtual void v9();
    virtual void Finish(int a, int b, int *state);                           // slot 10
};
class Parser_2340b0 {
public:
    char pad0[8];
    int state;              // 0x8

    void FUN_00233f20(char *text);
    bool FUN_002340b0(int a, int b, Reader *reader);
};


// 0x002340b0 FUN_002340b0 (146 B): equivalent/0x002340b0.cpp
// sym: ?FUN_002340b0@Parser_2340b0@fn_f53a6861@@QAE_NHHPAVReader@2@@Z @a81ed937cfc9 @wec8c03b3a9aa
// STATUS: equivalent (tools/equiv.py level 3: 8461 inputs, branch coverage 2/2)
// FUN_002340b0 @ 0x002340b0
bool Parser_2340b0::FUN_002340b0(int a, int b, Reader *reader)
{
    struct Frame {
        char buf[0x400];
        int pad;                // (the original leaves a word between the buffer and the cookie)
    } f;
    f.buf[0] = 0;
    memset(f.buf + 1, 0, sizeof(f.buf) - 1);
    reader->Read(a, b, f.buf, sizeof(f.buf));
    FUN_00233f20(f.buf);
    if (reader->HasMore()) {
        state = -1;
        reader->Finish(a, b, &state);
    }
    return true;
}

} // namespace fn_f53a6861
