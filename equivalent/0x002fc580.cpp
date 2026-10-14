// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 14/14)
// FUN_002fc580 @ 0x002fc580
struct Matrix {
    int m[16];
};

class Listener {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int arg);
};

struct Skeleton {
    char pad0[0x10];
    Matrix matrix;             // 0x10
    char pad50[0x70 - 0x50];
    Listener *listener;        // 0x70
    void FUN_002fd950(int arg);
    void FUN_002fdd80(int arg);
};

struct Track {
    char pad0[0x10];
    int count;                 // 0x10
    void FUN_0030ff80(int a);
    void FUN_0030ffb0(int index, int arg);
    void FUN_00310010(int index);
    void FUN_00310070();
};

class Animator {
public:
    char pad0[8];
    void *target;              // 0x08
    char pad0c[4];
    Skeleton *skeleton;        // 0x10
    Track *track;              // 0x14
    void FUN_002fc580(int arg, Matrix *out);
};

void Animator::FUN_002fc580(int arg, Matrix *out)
{
    if (target == 0)
        return;
    if (track != 0) {
        Listener *l = skeleton->listener;
        if (l != 0)
            l->v5(arg);
        Skeleton *sk = skeleton;
        sk->FUN_002fd950(arg);
        track->FUN_0030ff80(0);
        for (int i = 0; i < track->count; i++) {
            track->FUN_0030ffb0(i, arg);
            track->FUN_00310010(i);
        }
        sk->FUN_002fdd80(arg);
        track->FUN_00310070();
    } else {
        Listener *l = skeleton->listener;
        if (l != 0)
            l->v5(arg);
    }
    if (out != 0)
        *out = skeleton->matrix;
}
