// STATUS: equivalent (tools/equiv.py level 3: 3136 inputs, branch coverage 134/134)
// FEThingsBase::vfunc_37 @ 0x000f5330

class Item {
public:
    virtual int v0();
    virtual int type();
};


class Node {
public:
    char pad0[0x6c];
    int f6c;
    int f70;
    char pad74[0x1d84 - 0x74];
    char b1d84;
    void FUN_000e0170(int v);
    void FUN_000e3750(Node *v);
};

class Args {
public:
    virtual int v0();
    virtual int type();
};

class Param {
public:
    int FUN_000fad90();
    char FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    Item *FUN_000fb110();
    void FUN_000f9fb0();
    void FUN_000fa0a0();
    char FUN_000f9e90();
};

class Factory {
public:
    virtual Node *v0(int a, int b);
    virtual Node *v1(int a, int b);
    virtual Node *v2(int a, int b);
    virtual Node *v3(int a, int b);
    virtual Node *v4(int a, int b);
    virtual Node *v5(int a, int b);
    virtual Node *v6(int a, int b);
    virtual Node *v7(int a, int b);
    virtual Node *v8(int a, int b);
    virtual Node *v9(int a, int b);
    virtual Node *v10(int a, int b);
    virtual Node *v11(int a, int b);
    virtual Node *v12(int a, int b);
    virtual Node *v13(int a, int b);
    virtual Node *v14(int a, int b);
    virtual Node *v15(int a, int b);
    virtual Node *v16(int a, int b);
    virtual Node *v17(int a, int b);
    virtual Node *v18(int a, int b);
    virtual Node *v19(int a, int b);
    virtual Node *v20(int a, int b);
    virtual Node *v21(int a, int b);
    virtual Node *v22(int a);
    virtual Node *v23(int a, int b);
    virtual Node *v24(int a, int b);
    virtual Node *v25(int a, int b);
    virtual Node *v26(int a, int b);
    virtual Node *v27(int a, int b);
    virtual Node *v28(int a, int b);
    virtual Node *v29(int a, int b);
    virtual Node *v30(int a, int b);
    virtual Node *v31(int a, int b);
    virtual Node *v32(int a, int b);
    virtual Node *v33(int a, int b);
    virtual Node *v34(int a, int b);
    virtual Node *v35(int a, int b);
    virtual Node *v36(int a, int b);
    virtual Node *v37(int a, int b);
    virtual Node *v38(int a, int b);
    virtual Node *v39(int a, int b);
    virtual Node *v40(int a, int b);
    virtual Node *v41(int a, int b);
    virtual Node *v42(int a, int b);
    virtual Node *v43(int a, int b);
    virtual Node *v44(int a, int b);
};

class FEThingsBase {
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
    virtual char v37(Param *a0, Factory *a1, Args *a2);
    virtual void v38();
    virtual void v39();
    char pad04[0x1804 - 4];
    int f1804;
    int f1808;

    void FUN_000eff20(Param *a, Factory *b, int z, int k);
    void FUN_000e7ad0(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000e7930(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000f3940(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000f3f00(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000e7770(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000f3dc0(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000f3b20(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000f42c0(Param *p, Factory *f, Node *n, Item *i);
    void FUN_000f1e50(Param *p, Factory *f, Node *n, Item *i);
};

char FEThingsBase::v37(Param *a0, Factory *a1, Args *a2)
{
    Node *n;
    int t;

    switch (a2->type()) {
    case 0x9b3b78da:
        FUN_000eff20(a0, a1, 0, 0xb);
        return 1;
    case (int)0xccbb2461:
        FUN_000eff20(a0, a1, 0, 6);
        return 1;
    case (int)0xdf91462a:
        FUN_000eff20(a0, a1, 0, 8);
        return 1;
    case 0x11a78a91:
        FUN_000eff20(a0, a1, 0, 0xc);
        return 1;
    case 0x16b5f73c:
        FUN_000eff20(a0, a1, 0, 5);
        return 1;
    case 0x33873914:
        FUN_000eff20(a0, a1, 0, 0xa);
        return 1;
    case 0x2627546a:
        FUN_000eff20(a0, a1, 0, 7);
        return 1;
    case 0x4c8fab99:
        FUN_000eff20(a0, a1, 0, 0xd);
        return 1;
    case 0x5c000339:
        FUN_000eff20(a0, a1, 0, 9);
        return 1;
    case (int)0x80f230c2: {
        t = a0->FUN_000fad90();
        n = a1->v22(t);
        if (!a0->FUN_000f9ef0())
            a0->FUN_000fa0a0();
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50()) {
            if (a0->FUN_000fb110()->type() == 0x2d848685)
                n->FUN_000e0170(a0->FUN_000fad90());
            else
                a0->FUN_000fa0a0();
        }
        a0->FUN_000f9fb0();
        return 1;
    }
    case (int)0x9f62170f:
        t = a0->FUN_000fad90();
        n = a1->v32(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000e7ad0(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case (int)0xf801065b:
        t = a0->FUN_000fad90();
        n = a1->v31(t, 0);
        if (a0->FUN_000f9e90()) {
            const char *s = (const char *)a0->FUN_000fad90();
            const char *lit = "wrap";
            int i;
            for (i = 0; i < 5; i++) {
                if (s[i] != lit[i])
                    break;
            }
            if (i == 5)
                n->b1d84 = 1;
        }
        n->FUN_000e3750(a1->v29(t, 0));
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000e7930(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case (int)0xf71ffd40: {
        int x;
        t = a0->FUN_000fad90();
        if (a0->FUN_000f9e90())
            x = a0->FUN_000fad90();
        else
            x = 0;
        n = a1->v26(t, x);
        if (x == 0) {
            n->f6c = f1804;
            n->f70 = f1808;
        }
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3940(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    }
    case 0x028a7c50: {
        int x;
        t = a0->FUN_000fad90();
        if (a0->FUN_000f9e90())
            x = a0->FUN_000fad90();
        else
            x = 0;
        n = a1->v33(t, x);
        if (x == 0) {
            n->f6c = f1804;
            n->f70 = f1808;
        }
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3f00(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    }
    case 0x46fd849c: {
        int x;
        t = a0->FUN_000fad90();
        if (a0->FUN_000f9e90())
            x = a0->FUN_000fad90();
        else
            x = 0;
        n = a1->v25(t, x);
        if (x == 0) {
            n->f6c = f1804;
            n->f70 = f1808;
        }
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000e7770(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    }
    case 0x4a9bc1d7:
        t = a0->FUN_000fad90();
        n = a1->v28(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3dc0(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case 0x56b9eee7:
        t = a0->FUN_000fad90();
        n = a1->v27(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3b20(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case 0x5e3b266f:
        t = a0->FUN_000fad90();
        n = a1->v30(t, 0);
        if (a0->FUN_000f9e90()) {
            const char *s = (const char *)a0->FUN_000fad90();
            const char *lit = "wrap";
            int i;
            for (i = 0; i < 5; i++) {
                if (s[i] != lit[i])
                    break;
            }
            if (i == 5)
                n->b1d84 = 1;
        }
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f42c0(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case 0x7615e4bd:
        t = a0->FUN_000fad90();
        n = a1->v29(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f1e50(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    default:
        return 0;
    }
}
