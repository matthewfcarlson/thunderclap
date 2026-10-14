// STATUS: equivalent (tools/equiv.py level 3: 2012 inputs, branch coverage 88/88)
// FUN_00338030 @ 0x00338030
extern "C" long atol(const char *s);
extern "C" double __cdecl FUN_003458c1(const char *s);
extern "C" int __cdecl FUN_00337dc0(const char *s);
extern "C" char __cdecl FUN_00337e50(const char *s);
extern "C" char __cdecl FUN_00337370(const char *s);

class Pool_338030 {
public:
    void *FUN_00337d60(unsigned int size, int align);
};
extern Pool_338030 DAT_00565fc0;

class Loader_338030 {
public:
    char pad0[0x5108];
    int status;
    const char *FUN_00337460();
    void FUN_003374a0();
    void FUN_003375a0();
};

class AttrDef_338030 {
public:
    char pad0[4];
    char *name;
    int type;
    char *value;
    int FUN_00337ec0();
    bool FUN_00338030(Loader_338030 *ld);
};

static void CopyString(char **slot, const char *src)
{
    const char *e = src;
    while (*e++ != 0) {
    }
    char *d = (char *)DAT_00565fc0.FUN_00337d60((unsigned int)(e - src), 4);
    *slot = d;
    char c;
    do {
        c = *src++;
        *d++ = c;
    } while (c != 0);
}

bool AttrDef_338030::FUN_00338030(Loader_338030 *ld)
{
    const char *tok = ld->FUN_00337460();
    if (tok == 0)
        return false;
    CopyString(&name, tok);
    ld->FUN_003374a0();

    tok = ld->FUN_00337460();
    if (tok == 0)
        return false;
    type = FUN_00337dc0(tok);
    if (type == -1) {
        ld->status = 10;
        return false;
    }
    ld->FUN_003374a0();
    char *v = (char *)DAT_00565fc0.FUN_00337d60(FUN_00337ec0(), 4);
    value = v;

    switch (type) {
    case 0:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *v = FUN_00337e50(tok);
        ld->FUN_003374a0();
        return true;
    case 1: {
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003375a0();
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        if (FUN_00337370(tok)) {
            v[4] = 0;
            return true;
        }
        v[4] = 1;
        *(int *)(v + 8) = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 0xc) = atol(tok);
        ld->FUN_003374a0();
        return true;
    }
    case 2:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        CopyString((char **)(v + 4), tok);
        ld->FUN_003374a0();
        return true;
    case 3: {
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)v = (float)FUN_003458c1(tok);
        ld->FUN_003375a0();
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        if (FUN_00337370(tok)) {
            v[4] = 0;
            return true;
        }
        v[4] = 1;
        *(float *)(v + 8) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 0xc) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        return true;
    }
    case 4:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        CopyString((char **)v, tok);
        ld->FUN_003374a0();
        return true;
    case 5:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)v = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 4) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        return true;
    case 6:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)v = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 4) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 8) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        return true;
    case 7:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 4) = atol(tok);
        ld->FUN_003374a0();
        return true;
    case 8:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 4) = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 8) = atol(tok);
        ld->FUN_003374a0();
        return true;
    case 9: {
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        int r = FUN_00337dc0(tok);
        *(int *)v = r;
        *(int *)(v + 4) = 0;
        if (r == -1) {
            ld->status = 10;
            return false;
        }
        if (r == 9) {
            ld->status = 11;
            return false;
        }
        ld->FUN_003374a0();
        if (*(int *)v == 2) {
            tok = ld->FUN_00337460();
            if (tok == 0)
                return false;
            CopyString((char **)(v + 4), tok);
            ld->FUN_003374a0();
        }
        return true;
    }
    }
    return true;
}
