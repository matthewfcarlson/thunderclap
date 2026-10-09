struct Iter {
    int v;
};

int FUN_002611b0(int* p);
int FUN_002673a0(int a, int b);
int FUN_002610e0(int m, int* k);
void FUN_00261120(int m, int* k, Iter* it);

struct Helper {
    char d[16];
    Helper* Make(int a, int b);
    int Get();
    void Release();
    void Link(int x);
};

int __cdecl FUN_00261460(int* p) {
    int a = FUN_002611b0(p);
    int b = FUN_002611b0(p);
    char tmp[12];
    int key;
    Helper* h = ((Helper*)tmp)->Make(a, 2);
    int r = h->Get();
    key = FUN_002673a0(r, 0);
    ((Helper*)tmp)->Release();
    Helper* f = (Helper*)FUN_002610e0(*p, &key);
    if (!f) {
        Helper* g = ((Helper*)tmp)->Make(b, 2);
        FUN_00261120(*p, &key, (Iter*)g);
        ((Helper*)tmp)->Release();
        return b;
    }
    f->Link(b);
    return b;
}
