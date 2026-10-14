// STATUS: equivalent (tools/equiv.py level 3: 3105 inputs, branch coverage 59/66, incomplete)
// FEMemCardControl::vfunc_12 @ 0x000dbe20
class Sink_dbe20 {
public:
    virtual void v0();
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
    virtual void v12();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48(int mode);
};

struct Hub_dbe20 {
    char pad0[4];
    Sink_dbe20 *sink;
};

struct Holder_dbe20 {
    char pad0[8];
    Hub_dbe20 *hub;
};

struct Entry_dbe20 {
    char valid;
    char pad01[7];
    char locked;
    char pad09[0x3c - 9];
};

extern "C" int __cdecl FUN_0009fa70(int *v, int *lo, int *hi);

class FEMemCardControl {
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
    virtual char vfunc_12(int cmd, int unused);
    char pad04[0x10];
    Holder_dbe20 *holder;
    char pad18[0x1d0 - 0x18];
    int cursorId;
    int sel;
    char pad1d8[0x250 - 0x1d8];
    Entry_dbe20 entries[5];
    char pad37c[0x3a8 - 0x37c];
    char useMouse;
    char pad3a9[3];
    int state;
    char dirty;
    void FUN_000d9e40(int id);
    void FUN_000d8990(int id);
    void FUN_000d8dd0(int id);
    void FUN_000d8a90(int id);
    void FUN_000d9790(int id);
};

char FEMemCardControl::vfunc_12(int cmd, int unused)
{
    if (state != 3)
        return 1;
    switch (cmd) {
    case 8:
    case 11:
        if (useMouse) {
            int s = sel;
            if (entries[s].locked) {
                holder->hub->sink->v48(0);
                state = 0x19;
                FUN_000d9e40(cursorId);
                return 1;
            }
            if (entries[s].valid) {
                holder->hub->sink->v48(0);
                state = 8;
                FUN_000d8990(cursorId);
                return 1;
            }
            holder->hub->sink->v48(0);
            state = 4;
            FUN_000d8dd0(cursorId);
            return 1;
        }
        if (sel >= 0) {
            holder->hub->sink->v48(0);
            state = 9;
            FUN_000d8a90(cursorId);
            dirty = 1;
        }
        return 1;
    case 0:
        if (useMouse) {
            int old = sel;
            int v = old - 1;
            int lo = 0;
            int hi = 4;
            int r = FUN_0009fa70(&v, &lo, &hi);
            if (r == old)
                return 1;
            holder->hub->sink->v48(2);
            sel = r;
            return 1;
        } else {
            int old = sel;
            sel = old - 1;
            while (sel != -1) {
                int c = sel;
                if (c < 0)
                    c = 0;
                else if (c > 4)
                    c = 4;
                sel = c;
                if (entries[c].valid && !entries[c].locked) {
                    holder->hub->sink->v48(2);
                    return 1;
                }
                if (c == 0)
                    break;
                sel = sel - 1;
            }
            sel = old;
            return 1;
        }
    case 4: {
        int old = sel;
        if (old < 4 && !entries[old].valid && !entries[old + 1].valid)
            return 1;
        if (useMouse) {
            int v = old + 1;
            int lo = 0;
            int hi = 4;
            int r = FUN_0009fa70(&v, &lo, &hi);
            if (r == old)
                return 1;
            holder->hub->sink->v48(2);
            sel = r;
            return 1;
        }
        int c;
        do {
            c = sel + 1;
            if (c < 0)
                c = 0;
            else if (c > 4)
                c = 4;
            sel = c;
            if (entries[c].valid && !entries[c].locked) {
                holder->hub->sink->v48(2);
                return 1;
            }
        } while (c != 4);
        sel = old;
        return 1;
    }
    case 10:
        holder->hub->sink->v48(1);
        state = 0x1f;
        return 1;
    case 9:
        if (!useMouse)
            return 1;
        if (sel < 0)
            return 1;
        if (!entries[sel].valid)
            return 1;
        holder->hub->sink->v48(0);
        state = 0xd;
        FUN_000d9790(cursorId);
        dirty = 1;
        return 1;
    }
    return 0;
}
