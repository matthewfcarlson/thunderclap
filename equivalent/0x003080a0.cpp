// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 28/29, incomplete)
// FUN_003080a0 @ 0x003080a0
struct V3 {
    float x, y, z;
};

struct Stream {
    char FUN_002647e0(void* dst, int count, int size, int one);
};

struct Reader {
    char pad000[0x284];
    Stream* stream;
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    unsigned short FUN_00201750();
};

struct Vec {
    int a;
    int b;
    int c;
    void FUN_002ede00(int n);
};

struct Node {
    char pad04[8];
    int f08;
    int f0c;
    char pad10[4];
    Vec* children;
    void FUN_00306600(int a);
    void FUN_00306930(Node* child);
};

struct NodeA : Node {
    char pad18[0x48 - 0x18];
    Node* FUN_002efe50(V3* pos, int d);
};

struct NodeB : Node {
    char pad18[0x8c - 0x18];
    Node* FUN_002f3070(V3* a, V3* b, int r2, int r1, int flag);
};

struct NodeC : Node {
    char pad18[0xbc - 0x18];
    Node* FUN_002fbed0(V3* a, int* tri, V3* b, V3* c, V3* d);
};

struct NodeD : Node {
    char pad18[0x60 - 0x18];
    Node* FUN_0030e630(V3* a, V3* b);
};

struct NodeE : Node {
    char pad18[0x44 - 0x18];
    Node* FUN_00312900();
};

void* FUN_0008d690(unsigned int size);
Node* __cdecl FUN_003078a0(Reader* r);
void __cdecl FUN_00307810(Reader* r, V3* out);

struct Frame {
    int scratch;
    union {
        int d;
        unsigned char flag;
        int word;
    } u4;
    union {
        int a;
        Vec* vec;
    } u8;
    int b;
    int c;
    int r1;
    int tri[3];
    V3 v[9];
};

Node* __cdecl FUN_003080a0(Reader* r)
{
    Frame f;
    r->stream->FUN_002647e0(&f.u8.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.b, 1, 4, 1);
    r->stream->FUN_002647e0(&f.c, 1, 4, 1);
    Node* obj = 0;
    r->FUN_00266a30();
    int type = r->FUN_00266c30();
    switch (type) {
    case 0x07010002: {
        r->stream->FUN_002647e0(&f.u4.d, 1, 4, 1);
        FUN_00307810(r, &f.v[0]);
        void* mem = FUN_0008d690(0x48);
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((NodeA*)mem)->FUN_002efe50(&f.v[0], f.u4.d);
        break;
    }
    case 0x07010003: {
        r->stream->FUN_002647e0(&f.r1, 1, 4, 1);
        r->stream->FUN_002647e0(&f.scratch, 1, 4, 1);
        f.u4.flag = r->FUN_00201750() != 0;
        FUN_00307810(r, &f.v[3]);
        FUN_00307810(r, &f.v[5]);
        void* mem = FUN_0008d690(0x8c);
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((NodeB*)mem)->FUN_002f3070(&f.v[3], &f.v[5], f.scratch, f.r1, f.u4.word);
        break;
    }
    case 0x07010004: {
        r->stream->FUN_002647e0(&f.scratch, 1, 4, 1);
        f.tri[0] = f.scratch;
        r->stream->FUN_002647e0(&f.scratch, 1, 4, 1);
        f.tri[1] = f.scratch;
        r->stream->FUN_002647e0(&f.scratch, 1, 4, 1);
        f.tri[2] = f.scratch;
        FUN_00307810(r, &f.v[4]);
        FUN_00307810(r, &f.v[2]);
        FUN_00307810(r, &f.v[1]);
        FUN_00307810(r, &f.v[7]);
        void* mem = FUN_0008d690(0xbc);
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((NodeC*)mem)->FUN_002fbed0(&f.v[4], f.tri, &f.v[2], &f.v[1], &f.v[7]);
        break;
    }
    case 0x07010005: {
        FUN_00307810(r, &f.v[8]);
        FUN_00307810(r, &f.v[6]);
        void* mem = FUN_0008d690(0x60);
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((NodeD*)mem)->FUN_0030e630(&f.v[8], &f.v[6]);
        break;
    }
    case 0x07010006: {
        void* mem = FUN_0008d690(0x44);
        if (mem != 0)
            obj = ((NodeE*)mem)->FUN_00312900();
        else
            obj = 0;
        r->stream->FUN_002647e0(&f.scratch, 1, 4, 1);
        break;
    }
    case 0x0701000a:
        obj = FUN_003078a0(r);
        break;
    default:
        break;
    }
    r->FUN_00266be0();
    obj->FUN_00306600(f.u8.a);
    int count = f.c;
    obj->f0c = f.b;
    if (count > 0) {
        void* mem = FUN_0008d690(0x10);
        Vec* vec = (Vec*)mem;
        f.u8.vec = vec;
        if (mem != 0) {
            vec->a = 0;
            vec->b = 0;
            vec->c = 0;
        } else {
            vec = 0;
        }
        obj->children = vec;
        vec->FUN_002ede00(count);
        while (count > 0) {
            r->FUN_00266a30();
            Node* child = FUN_003080a0(r);
            r->FUN_00266be0();
            obj->FUN_00306930(child);
            count--;
        }
    }
    return obj;
}
