// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 28/28)
// FUN_002ee260 @ 0x002ee260
struct V3_2ee260 {
    float x, y, z;
};

class Bounds_2ee260 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_2ee260 *GetPos();
    virtual void v5();
    virtual int GetKind();
    char pad04[0x24];
    float halfX;
    char pad2c[4];
    float halfZ;
    float limit;
};

class Obj_2ee260 {
public:
    virtual void AddRef();
    char pad04[0x1c];
    Bounds_2ee260 *bounds;
    char pad24[0x2c];
    bool listed;
};

struct Entry_2ee260 {
    Obj_2ee260 *obj;
    float x0;
    float x1;
    float z0;
    float z1;
};

class Tracker_2ee260 {
public:
    char pad0[4];
    Obj_2ee260 **end;
    Obj_2ee260 **capEnd;
    char padc[8];
    Obj_2ee260 **sorted;
    unsigned int sortedCount;
    float maxA;
    float maxB;
    Entry_2ee260 *entries;
    unsigned int entryCount;

    void FUN_002ee260(Obj_2ee260 *obj);
};

void Tracker_2ee260::FUN_002ee260(Obj_2ee260 *obj)
{
    if (end < capEnd) {
        Obj_2ee260 **p = end;
        end = p + 1;
        if (p != 0)
            *p = obj;
    }
    obj->AddRef();
    if (obj->listed) {
        Bounds_2ee260 *b;
        b = obj->bounds;
        float x0 = b->GetPos()->x - b->halfX;
        b = obj->bounds;
        float x1 = b->halfX + b->GetPos()->x;
        b = obj->bounds;
        float z0 = b->GetPos()->z - b->halfZ;
        b = obj->bounds;
        float z1 = b->GetPos()->z + b->halfZ;
        entries[entryCount].obj = obj;
        entries[entryCount].x0 = x0;
        entries[entryCount].x1 = x1;
        entries[entryCount].z0 = z0;
        entries[entryCount].z1 = z1;
        entryCount++;
        if (obj->bounds->GetKind() == 8)
            return;
        unsigned int k = entryCount;
        while (k > 1) {
            if (entries[k - 1].obj->bounds->GetKind() != 8) {
                float hi = entries[k - 1].x0;
                float lo = entries[k - 2].x0;
                if (entries[k - 2].obj->bounds->GetKind() != 8) {
                    if (!(hi < lo))
                        return;
                }
                Entry_2ee260 *p1 = &entries[k - 1];
                Entry_2ee260 tmp = *p1;
                *p1 = entries[k - 2];
                entries[k - 2] = tmp;
            }
            k--;
        }
    } else {
        sorted[sortedCount] = obj;
        sortedCount++;
        if (obj->bounds->limit > maxA)
            maxA = obj->bounds->limit;
        if (obj->bounds->limit > maxB)
            maxB = obj->bounds->limit;
        unsigned int k = sortedCount;
        while (k > 1) {
            float a = sorted[k - 1]->bounds->GetPos()->x;
            if (!(a < sorted[k - 2]->bounds->GetPos()->x))
                return;
            Obj_2ee260 *lo = sorted[k - 2];
            Obj_2ee260 *hi = sorted[k - 1];
            sorted[k - 1] = lo;
            sorted[k - 2] = hi;
            k--;
        }
    }
}
