// STATUS: equivalent (tools/equiv.py level 3: 3180 inputs, branch coverage 84/84)
// FUN_0028e160 @ 0x0028e160
void *__cdecl FUN_0008d690(unsigned int size);

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

struct Prim_28e160 {
    char pad00[4];
    int f4;
    int f8;
    char padc[8];
    void *f14;
    void *f18;
};

struct Parent_28e160;

struct Frame_28e160 {
    int l14, l10, lc, l8, l4;
};

struct Mem_28e160 {
    Prim_28e160 *FUN_0028c0b0(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028d150(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028d490(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028d750(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028dae0(int count, Parent_28e160 *p);
};

struct Parent_28e160 {
    Mem_28e160 *FUN_002888c0(int size, int tag);
};

Prim_28e160 *__stdcall FUN_0028e160(Reader *R, int unused, Parent_28e160 *parent)
{
    Frame_28e160 f;
    Reader *Rr = R;
    Parent_28e160 *par = parent;
    int *pcount = (int *)&R;        // the first argument slot is reused for counts
    int *pval = (int *)&parent;     // and the third for the chunk values
    int count;
    Prim_28e160 *obj;
    int id = Rr->FUN_00266c30() - 0x121105;
    if ((unsigned int)id > 0xf)
        return 0;
    if (id == 0) {
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l14, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028c0b0(count, 0) : 0;
        } else {
            Mem_28e160 *m = par->FUN_002888c0(0x1c, 7);
            obj = m ? m->FUN_0028c0b0(count, par) : 0;
        }
        obj->f8 = f.l14;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 4, 4, 1);
        if (f.l10 != 1) {
            for (unsigned int i = 0; i < (unsigned int)count; i++) {
                int *p = (int *)((char *)obj->f18 + i * 16);
                f.l10 = p[0];
                f.lc = p[1];
                int e2 = p[2];
                f.l4 = p[3];
                p = (int *)((char *)obj->f18 + i * 16);
                p[0] = f.lc;
                f.l8 = e2;
                ((float *)p)[1] = *(float *)&f.l8;
                ((float *)p)[2] = *(float *)&f.l4;
                ((float *)p)[3] = *(float *)&f.l10;
            }
        }
    } else if (id == 12) {
        Rr->stream->FUN_002647e0(&f.l14, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028d150(count, 0) : 0;
        } else {
            Mem_28e160 *m = par->FUN_002888c0(0x1c, 7);
            obj = m ? m->FUN_0028d150(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 4, 2, 1);
        if (f.l14 != 1) {
            for (unsigned int i = 0; i < (unsigned int)count; i++) {
                unsigned int lo = ((unsigned int *)obj->f18)[i * 2];
                f.lc = ((unsigned int *)obj->f18)[i * 2 + 1];
                unsigned short *w = (unsigned short *)obj->f18;
                w[i * 4 + 0] = (unsigned short)(lo >> 16);
                w[i * 4 + 1] = (unsigned short)f.lc;
                w[i * 4 + 2] = (unsigned short)((unsigned int)f.lc >> 16);
                w[i * 4 + 3] = (unsigned short)lo;
                f.l10 = lo;
            }
        }
    } else if (id == 13) {
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028d490(count, 0) : 0;
        } else {
            Mem_28e160 *m = par->FUN_002888c0(0x1c, 7);
            obj = m ? m->FUN_0028d490(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 3, 2, 1);
    } else if (id == 14) {
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028d750(count, 0) : 0;
        } else {
            Mem_28e160 *m = par->FUN_002888c0(0x1c, 7);
            obj = m ? m->FUN_0028d750(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count, 4, 1);
    } else if (id == 15) {
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028dae0(count, 0) : 0;
        } else {
            Mem_28e160 *m = par->FUN_002888c0(0x1c, 7);
            obj = m ? m->FUN_0028dae0(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 3, 1, 1);
    } else {
        return 0;
    }
    while (Rr->FUN_002669f0()) {
        if (Rr->FUN_00266a30() == 0x121110) {
            Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
            Rr->stream->FUN_002647e0(pval, 1, 4, 1);
            obj->f4 = *pval;
        }
        Rr->FUN_00266be0();
    }
    return obj;
}
