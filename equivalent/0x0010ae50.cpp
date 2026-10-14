// STATUS: equivalent (tools/equiv.py level 3: 183 inputs, branch coverage 48/50, incomplete)
// FUN_0010ae50 @ 0x0010ae50
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void *__cdecl FUN_0008d6d0(int size);
void __cdecl thunk_FUN_00267090(void *p);

struct V3_10ae50 {
    float x, y, z;
    bool FUN_0022d2b0(V3_10ae50 *out, float eps);
    float FUN_0022d110();
};

struct Part_10ae50 {
    char pad0[0x129];
    char flag129;
};

struct Item_10ae50 {
    char pad0[0x1ca0];
    Part_10ae50 *part;
};

struct Group_10ae50 {
    char pad0[0xc];
    int count;
    Item_10ae50 *FUN_00024190(int index);
    bool FUN_00025d30(Item_10ae50 *item);
};

struct World {
    char pad0[0x20];
    Group_10ae50 *group;
};

float __cdecl FUN_0010ac60(void *a, Item_10ae50 *item, void *b, V3_10ae50 *out);

float __cdecl FUN_0010ae50(World *w, void *a, void *b, V3_10ae50 *dir, V3_10ae50 *sum, bool mark, Item_10ae50 **hit)
{
    int n = w->group->count;
    float best = -1.0f;
    float r;
    sum->z = 0.0f;
    sum->y = 0.0f;
    sum->x = 0.0f;
    if (hit)
        *hit = 0;
    V3_10ae50 *arr = (V3_10ae50 *)FUN_0008d6d0(n * 12);
    for (int k = 0; k < n; k++) {
        arr[k].z = 0.0f;
        arr[k].y = 0.0f;
        arr[k].x = 0.0f;
    }
    for (int i = 0; i < n; i++) {
        V3_10ae50 wv;
        wv.x = 0.0f;
        wv.y = 0.0f;
        wv.z = 0.0f;
        Item_10ae50 *item = w->group->FUN_00024190(i);
        if (item == 0)
            continue;
        if (w->group->FUN_00025d30(item))
            continue;
        if ((void *)item == a)
            continue;
        r = FUN_0010ac60(a, item, b, &wv);
        if (r < 0.0f || !(r >= 0.0f))
            continue;
        for (int k = 0; k < n; k++) {
            V3_10ae50 t;
            t.x = 0.0f;
            t.y = 0.0f;
            t.z = 0.0f;
            if (!arr[k].FUN_0022d2b0(&t, 1e-5f)) {
                if (wv.z * arr[k].z + wv.y * arr[k].y + wv.x * arr[k].x < -0.7f) {
                    arr[k].z = 0.0f;
                    arr[k].y = 0.0f;
                    arr[k].x = 0.0f;
                    r = -1.0f;
                }
            }
        }
        if (r < 0.0f)
            continue;
        int j;
        for (j = 0; j < n; j++) {
            V3_10ae50 t2;
            t2.x = 0.0f;
            t2.y = 0.0f;
            t2.z = 0.0f;
            if (arr[j].FUN_0022d2b0(&t2, 1e-5f))
                break;
        }
        if (j < n)
            arr[j] = wv;
        if (mark) {
            Part_10ae50 *p = item->part;
            if (p)
                p->flag129 = 1;
        }
        if (wv.x * dir->x + wv.y * dir->y + wv.z * dir->z < 0.0f) {
            dir->z = 0.0f;
            dir->y = 0.0f;
            dir->x = 0.0f;
        }
        if (best < 0.0f || r < best) {
            best = r;
            if (hit)
                *hit = item;
        }
    }
    for (int j = 0; j < n; j++) {
        sum->x = arr[j].x + sum->x;
        sum->y = arr[j].y + sum->y;
        sum->z = sum->z + arr[j].z;
    }
    sum->FUN_0022d110();
    thunk_FUN_00267090(arr);
    return best;
}
