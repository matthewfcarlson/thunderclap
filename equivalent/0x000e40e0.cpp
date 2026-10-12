// STATUS: equivalent (tools/equiv.py level 3: 2843 inputs, branch coverage 49/53, incomplete)
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
