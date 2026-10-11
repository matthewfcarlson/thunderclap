// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 18/18)
// FUN_0015c2a0 @ 0x0015c2a0
struct Table {
    char pad0[0x2c];
    int count;
    float FUN_00226960(int index, float angle);
};

class RangeSet {
public:
    char pad0[0x20];
    Table *table;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;

    void FUN_0015c2a0(float a0, float a1, float a2, float a3, float a4, float a5);
};

void RangeSet::FUN_0015c2a0(float a0, float a1, float a2, float a3, float a4, float a5)
{
    if (a3 < 0.0f)
        f34 = table->FUN_00226960(table->count - 1, 0.0f);
    else
        f34 = a3;

    if (a4 < 0.0f) {
        f38 = table->FUN_00226960(table->count - 1, 1.5707964f);
        f40 = table->FUN_00226960(table->count - 1, 4.7123890f);
    } else {
        f38 = a4;
        f40 = a4;
    }

    if (a5 < 0.0f)
        f3c = table->FUN_00226960(table->count - 1, 3.1415927f);
    else
        f3c = a5;

    int n = table->count;
    if (a0 < 0.0f) {
        if (n == 3)
            f24 = table->FUN_00226960(1, 0.0f);
        else
            f24 = table->FUN_00226960(table->count - 1, 0.0f) * 0.5f;
    } else {
        f24 = a0;
    }

    if (a1 < 0.0f) {
        if (n == 3) {
            f28 = table->FUN_00226960(1, 1.5707964f);
            f30 = table->FUN_00226960(1, 4.7123890f);
        } else {
            f28 = table->FUN_00226960(table->count - 1, 1.5707964f) * 0.5f;
            f30 = table->FUN_00226960(table->count - 1, 4.7123890f) * 0.5f;
        }
    } else {
        f28 = a1;
        f30 = a1;
    }

    if (a2 < 0.0f) {
        if (n == 3)
            f2c = table->FUN_00226960(1, 3.1415927f);
        else
            f2c = table->FUN_00226960(table->count - 1, 3.1415927f) * 0.5f;
    } else {
        f2c = a2;
    }
}
