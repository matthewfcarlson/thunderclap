// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e3f20..0x000e4330 (kind game, layer game, confidence high), dominant class ImageSelector
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa86e765 {
#define TREE_TU_END }
namespace fn_fa86e765 {} using namespace fn_fa86e765;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fa86e765 {
class C_e3fe0 {
    char pad[0x290];

  public:
    unsigned int value;
};
class D {
  public:
    void Cleanup_000f8b90(int);
};
struct Worker_e4060 {
};
struct Z {
    char pad[8];
    Worker_e4060* w;
};
struct Y_e4060 {
    char pad[4];
    Z* z;
};
struct X_e4060 {
    char pad[8];
    Y_e4060* y;
};
class Owner_e4060 {
  public:
    char pad[0x14];
    X_e4060* mA;
    char pad2[0x294];
    int* slot;
    void Update(void* arg);
};

} // namespace fn_fa86e765

// 0x000e3f20 FUN_000e3f20 (126 B): matches/0x000e3f20.cpp
// sym: ?FUN_000e3f20@Obj_e3f20@owners@@QAEXPAU12@@Z
void owners::Obj_e3f20::FUN_000e3f20(owners::Obj_e3f20* other) {
    Base(other);
    memcpy((char*)this + 0x118, (char*)other + 0x118, 40);
    int* d = (int*)((char*)this + 0x290);
    int* s = (int*)((char*)other + 0x290);
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = s[5];
    d[6] = s[6];
}

namespace fn_fa86e765 {

// 0x000e3fe0 FUN_000e3fe0 (7 B): matches/0x000e3fe0.cpp
// sym: ?FUN_000e3fe0@fn_fa86e765@@YIIPAVC_e3fe0@1@@Z
unsigned int __fastcall FUN_000e3fe0(C_e3fe0* self) {
    return self->value;
}

} // namespace fn_fa86e765

// 0x000e4000 FUN_000e4000 (7 B): matches/0x000e4000.cpp
// sym: ?FUN_000e4000@A_e4000@owners@@QAEIXZ
unsigned int owners::A_e4000::FUN_000e4000() {
    return x;
}


// 0x000e4010 ImageSelector::vfunc_23 (7 B): matches/0x000e4010.cpp
// sym: ?vfunc_23@ImageSelector@@UAEHXZ
int ImageSelector::vfunc_23() {
    return this->f_2a8;
}


// 0x000e4020 FUN_000e4020 (32 B): matches/0x000e4020.cpp
// sym: ?FUN_000e4020@ImageSelector@@QAEXXZ
void ImageSelector::FUN_000e4020() {
    if ((*(D * *)&this->f_2ac))
        (*(D * *)&this->f_2ac)->Cleanup_000f8b90(this->f_2a8);
    vfunc_0();
}


// 0x000e4040 ImageSelector::vfunc_1 (24 B): matches/0x000e4040.cpp
// sym: ?vfunc_1@ImageSelector@@UAEXH@Z
void ImageSelector::vfunc_1(int param) {
    if (param == this->f_2ac)
        this->f_2a8 = *(int*)(this->f_2ac + 0x40);
}

namespace fn_fa86e765 {

// 0x000e4060 FUN_000e4060 (67 B): matches/0x000e4060.cpp
// sym: ?Update@Owner_e4060@fn_fa86e765@@QAEXPAX@Z
void Owner_e4060::Update(void* arg) {
    int* p = ((int *)((owners::Obj_f8d70 *)(mA->y->z->w))->FUN_000f8d70((hulk_intptr)arg));
    slot = p;
    if (p) {
        int i = 0;
        int* q = p + 1;
        do {
            if (*q == 0)
                break;
            ++i;
            ++q;
        } while (i < 4);
        if (i != 4)
            p[i + 1] = (hulk_intptr)this;
    }
}

} // namespace fn_fa86e765

// 0x000e40b0 ImageSelector::vfunc_10 (22 B): matches/0x000e40b0.cpp
// sym: ?vfunc_10@ImageSelector@@UAEDHH@Z
char ImageSelector::vfunc_10(int x, int y) {
    if (x != 0) {
        if (x == 4)
            return 1;
        return 0;
    }
    return 1;
}


// 0x000e40d0 ImageSelector::vfunc_11 (5 B): matches/0x000e40d0.cpp
// sym: ?vfunc_11@ImageSelector@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool ImageSelector::vfunc_11(int , int ) {
    return false;
}


// 0x000e40e0 ImageSelector::vfunc_12 (519 B): equivalent/0x000e40e0.cpp [wrapped: conflict: ImageSelector]
// sym: ?vfunc_12@ImageSelector@fn_000e40e0@@UAE_NHH@Z @1a5dbd2c1e3a @w29caba2edf8a
namespace fn_000e40e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2852 inputs, branch coverage 52/55, incomplete)
// ImageSelector::vfunc_12 @ 0x000e40e0
struct SelectionListener {
    void FUN_000f8b90(int index);
};

class Feedback {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void Play(int kind);
};

struct FeedbackHolder {
    char pad00[4];
    Feedback* feedback;
};

struct OwnerObject {
    char pad00[8];
    FeedbackHolder* holder;
};

class ImageSelector {
public:
    virtual void Refresh();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual bool vfunc_12(int cmd, int unused);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();

    char pad04[0x14 - 4];
    OwnerObject* owner;
    char pad18[0x150 - 0x18];
    int cells[81];
    int rows;
    int columns;
    char pad29c[0x2a8 - 0x29c];
    int index;
    SelectionListener* listener;

    void FUN_000e4020();
};

bool ImageSelector::vfunc_12(int cmd, int unused)
{
    int newIndex = 0;
    bool direct = false;

    switch (cmd) {
    case 0: {
        int idx = index;
        int cols = columns;
        int row = idx / cols;
        int col = idx % cols;
        if (row == 0)
            return false;
        if (cells[col + row * 8 - 8] != 0) {
            index = idx - cols;
            direct = true;
        } else {
            if (row < 0)
                return false;
            bool found = false;
            for (int r = row; r >= 0 && !found; r--) {
                for (int c = cols - 1; c >= 0; c--) {
                    if (cells[r * 8 + c] != 0) {
                        newIndex = c + cols * r;
                        found = true;
                        break;
                    }
                }
            }
            if (!found)
                return false;
        }
        break;
    }
    case 4: {
        int idx = index;
        int cols = columns;
        int row = idx / cols;
        int col = idx % cols;
        int rowCount = rows;
        if (row == rowCount - 1)
            return false;
        if (cells[col + row * 8 + 8] != 0) {
            index = cols + idx;
            direct = true;
        } else {
            if (row + 1 >= rowCount)
                return false;
            bool found = false;
            for (int r = row + 1; r < rows && !found; r++) {
                for (int c = 0; c < cols; c++) {
                    if (cells[r * 8 + c] != 0) {
                        newIndex = c + cols * r;
                        found = true;
                        break;
                    }
                    if (c + 1 >= columns)
                        break;
                }
            }
            if (!found)
                return false;
        }
        break;
    }
    case 2: {
        int cols = columns;
        int total = rows * cols;
        if (total <= 1)
            return false;
        bool found = false;
        for (int step = 1; step < total; step++) {
            int pos = (index + step) % total;
            if (cells[pos % cols + pos / cols * 8] != 0) {
                newIndex = pos;
                found = true;
                break;
            }
        }
        if (!found)
            return false;
        break;
    }
    case 6: {
        int cols = columns;
        int total = rows * cols;
        if (total <= 1)
            return false;
        bool found = false;
        for (int step = 1; step < total; step++) {
            int pos = index - step;
            if (pos < 0)
                pos += total;
            if (cells[pos % cols + pos / cols * 8] != 0) {
                newIndex = pos;
                found = true;
                break;
            }
        }
        if (!found)
            return false;
        break;
    }
    default:
        return false;
    }

    if (direct) {
        FUN_000e4020();
    } else {
        SelectionListener* l = listener;
        index = newIndex;
        if (l)
            l->FUN_000f8b90(newIndex);
        Refresh();
    }
    owner->holder->feedback->Play(3);
    return true;
}
} // namespace fn_000e40e0


// 0x000e4310 ImageSelector::vfunc_13 (15 B): matches/0x000e4310.cpp
// sym: ?vfunc_13@ImageSelector@@UAEXH@Z
void ImageSelector::vfunc_13(int ) {
    this->f_148 = this->f_14c;
}


// 0x000e4320 ImageSelector::vfunc_14 (12 B): matches/0x000e4320.cpp
// sym: ?vfunc_14@ImageSelector@@UAEXH@Z
void ImageSelector::vfunc_14(int ) {
    this->f_148 = this->f_44;
}

