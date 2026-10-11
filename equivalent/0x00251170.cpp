// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 26/26)
// audio::SeqActionStopTrack::vfunc_1 @ 0x00251170
struct Str {
    char* data;
    short mode;
    short pad6;
    short len;
    short pad10;
    Str* FUN_0023fac0();
    Str* FUN_00240170(const Str* src);
    const char* FUN_0023fb00();
};
extern "C" void __fastcall FUN_00240060(Str* s);
struct Table { char pad[0x10]; };
struct Node;
struct Item;
struct Pair { int a; int b; };
struct Mgr {
    char pad[0x5c];
    Table table;
};
struct Ctx {
    char pad[0x3c];
    Mgr* mgr;
};
struct StopData {
    char pad[8];
    int w8;
    int wc;
    Str name;
    char flag1c;
};
void FUN_002613b0(Table* t, Str* out, Str* in);
int FUN_002673a0(const char* s, int seed);
Node* FUN_0024a370(Mgr* m, int* key);
Node* FUN_002495c0(Mgr* m);
Item* FUN_002495f0(Node* n);
int FUN_00247930(Mgr* m, Item* it);
Item* FUN_00249600(Node* n, Item* it);
void FUN_00247b30(Mgr* m, Item* it, Pair* p, int z);
Node* FUN_002495e0(Mgr* m, Node* n);

class SeqActionStopTrack {
public:
    virtual void v0();
    virtual void vfunc_1(Ctx* ctx);
    int pad04;
    StopData* data;
    int field0c;
};
void SeqActionStopTrack::vfunc_1(Ctx* ctx) {
    Mgr* mgr = ctx->mgr;
    Str track;
    track.FUN_0023fac0();
    Str src;
    src.FUN_00240170(&data->name);
    FUN_002613b0(&ctx->mgr->table, &track, &src);
    FUN_00240060(&src);
    int key = FUN_002673a0(track.FUN_0023fb00(), 0);
    Node* target = FUN_0024a370(ctx->mgr, &key);
    if (target != 0) {
        Pair p;
        p.a = data->wc;
        p.b = data->w8;
        if (data->flag1c != 0) {
            Node* n = FUN_002495c0(mgr);
            while (n != 0) {
                if (n != target) {
                    Item* it = FUN_002495f0(n);
                    while (it != 0) {
                        int k = FUN_00247930(mgr, it);
                        if (k != 0 && k != 5) {
                            FUN_00247b30(mgr, it, &p, 0);
                            break;
                        }
                        it = FUN_00249600(n, it);
                    }
                }
                n = FUN_002495e0(mgr, n);
            }
        } else {
            Item* it = FUN_002495f0(target);
            while (it != 0) {
                int k = FUN_00247930(mgr, it);
                if (k != 0 && k != 5) {
                    FUN_00247b30(mgr, it, &p, 0);
                    break;
                }
                it = FUN_00249600(target, it);
            }
        }
    }
    field0c = 0;
    FUN_00240060(&track);
}
