// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 64/71, incomplete)
// FUN_0025dd00 @ 0x0025dd00
class Controller;

class Listener {
public:
    virtual void Tick(Controller *c);
    virtual void v1(Controller *c);
    virtual void v2(Controller *c);
    virtual void v3(Controller *c);
    virtual void Stop(Controller *c);
    virtual int Poll(Controller *c);
    virtual void Release(Controller *c);
    Listener *nextLink;    // intrusive link at +4
};

struct Link {
    Listener *item;
};

struct Handle {
    char pad0[0xc0];
    int state;
};

struct Pending {
    void FUN_0024a280(int arg);
};

int __cdecl FUN_0024afe0(Handle *h);
void __cdecl FUN_0024c0c0(Handle *h);

class Controller {
public:
    char pad0[8];
    Pending pending;       // 0x08
    char pad09[0x34 - 9];
    Handle *handle;        // 0x34
    char pad38[0x40 - 0x38];
    char *listeners;       // 0x40, link at +4 inside each Listener
    char pad44[4];
    int busy;              // 0x48
    char pad4c[4];
    char *tickers;         // 0x50
    char pad54[4];
    int state;             // 0x58
    void FUN_0025d7c0();
    void FUN_0025d7f0();
    char FUN_0025da00();
    void FUN_0025dd00(int arg);
};

void Controller::FUN_0025dd00(int arg)
{
    pending.FUN_0024a280(arg);
    switch (state) {
    case 1: {
        FUN_0025d7c0();
        FUN_0025d7f0();
        FUN_0025da00();
        Listener *l = listeners ? (Listener *)(listeners - 4) : 0;
        if (l != 0) {
            int r = l->Poll(this);
            if (r == 2 || r == 0) {
                Handle *h = handle;
                state = 2;
                if (h != 0 && FUN_0024afe0(h) == 2)
                    state = 3;
            }
        } else {
            state = 2;
        }
        break;
    }
    case 3:
        if (busy == 0) {
            if (handle == 0 || FUN_0024afe0(handle) != 2)
                state = 5;
        }
        break;
    case 4: {
        Listener *l = listeners ? (Listener *)(listeners - 4) : 0;
        if (l != 0) {
            if (l->Poll(this) != 4)
                state = 2;
        } else {
            state = 2;
        }
        break;
    }
    case 5: {
        FUN_0025d7f0();
        int active = 0;
        if (handle != 0) {
            int r = FUN_0024afe0(handle);
            if (r != 5 && r != 0)
                FUN_0024c0c0(handle);
            active = 1;
        }
        Listener *l = listeners ? (Listener *)(listeners - 4) : 0;
        while (l != 0) {
            int r = l->Poll(this);
            if (r != 5 && r != 0)
                l->Stop(this);
            if (r != 0)
                active++;
            l->Release(this);
            char *next = (char *)l->nextLink;
            if (next == 0)
                break;
            l = (Listener *)(next - 4);
        }
        if (active == 0)
            state = 0;
        break;
    }
    }
    if (state == 2 || state == 4 || state == 3) {
        unsigned int n = 0;
        do {
            unsigned int i = 0;
            do {
                if (tickers == 0)
                    break;
                Listener *l = (Listener *)(tickers - 4);
                if (l == 0 || busy == 0x1e)
                    break;
                l->Tick(this);
                i++;
            } while (i < 5);
            FUN_0025d7f0();
            n++;
            if (FUN_0025da00() == 0)
                break;
        } while (n < 5);
    }
}
