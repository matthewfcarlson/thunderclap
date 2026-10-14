// STATUS: equivalent (tools/equiv.py level 3: 172 inputs, branch coverage 39/39)
// FUN_003027b0 @ 0x003027b0
extern float DAT_004d2f7c;

struct Body_3027b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();             // 0x18
    char pad4[0x34 - 4];
    float size;                     // 0x34
};

class Resolver_3027b0 {
public:
    char pad0[0xc];
    float threshold;                // 0xc
    char pad10[0x34 - 0x10];
    unsigned char busyA;            // 0x34
    unsigned char busyB;            // 0x35

    void FUN_003023b0(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301790(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301410(Body_3027b0 *a, Body_3027b0 *b, float c);
    void FUN_00301460(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_003014f0(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_003012d0(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301310(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301e10(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00302200(Body_3027b0 *a, Body_3027b0 *b);
    char FUN_003027b0(Body_3027b0 *a1, Body_3027b0 *a2);
};

char Resolver_3027b0::FUN_003027b0(Body_3027b0 *a1, Body_3027b0 *a2)
{
    FUN_003023b0(a1, a2);

    bool pairHandled = false;
    if (a1->size < a2->size) {
        if (DAT_004d2f7c * a1->size < threshold) {
            pairHandled = true;
            busyA = 1;
            switch (a2->type()) {
            case 2:
                FUN_00301460(a2, a1);
                break;
            case 5:
                FUN_00301410(a2, a1, a1->size);
                break;
            case 8:
                FUN_00301790(a2, a1);
                break;
            default:
                FUN_003014f0(a1, a2);
                break;
            }
        }
    } else {
        if (DAT_004d2f7c * a2->size < threshold) {
            pairHandled = true;
            busyB = 1;
            switch (a1->type()) {
            case 2:
                FUN_00301460(a1, a2);
                break;
            case 5:
                FUN_00301410(a1, a2, a2->size);
                break;
            case 8:
                FUN_00301790(a1, a2);
                break;
            default:
                FUN_003014f0(a1, a2);
                break;
            }
        }
    }

    if (!pairHandled) {
        switch (a1->type()) {
        case 2:
            if (a2->type() == 2)
                FUN_00301e10(a1, a2);
            break;
        case 5: {
            int t = a2->type();
            if (t == 2)
                FUN_00301310(a1, a2);
            else if (t == 5)
                FUN_003012d0(a1, a2);
            break;
        }
        case 7: {
            int t = a2->type();
            if (t == 2)
                FUN_00301460(a2, a1);
            else if (t == 5)
                FUN_00301410(a2, a1, a1->size);
            else if (t == 7)
                FUN_00302200(a1, a2);
            else
                FUN_003014f0(a1, a2);
            break;
        }
        case 8:
            if (a2->type() != 8)
                FUN_00301790(a1, a2);
            break;
        default:
            FUN_003014f0(a1, a2);
            break;
        }
    }

    busyA = 0;
    busyB = 0;
    return 0;
}
