// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 22/22)
// FUN_00067ce0 @ 0x00067ce0
struct Rec_67ce0 {
    int tag;
    float x, y, z;
    float radius;
    int pad14;
    int idLo;
    int idHi;
};

struct Sphere_67ce0 {
    float x, y, z;
    float radius;
};

struct V3_67ce0 { float x, y, z; };

struct ObjId { int lo; int hi; };

extern int DAT_004dcf00;
extern int DAT_004dcf04;

class Tracker_67ce0 {
public:
    bool run(const ObjId* id, int skipTag, const Sphere_67ce0* s, V3_67ce0* outPos, void** outObj);
    char p0[8];
    void* objs[64];
    Rec_67ce0 recs[64];
};

bool Tracker_67ce0::run(const ObjId* id, int skipTag, const Sphere_67ce0* s, V3_67ce0* outPos, void** outObj)
{
    int count = 0;
    outPos->z = 0;
    outPos->y = 0;
    outPos->x = 0;
    for (int i = 0; i < 64; i++) {
        void* obj = objs[i];
        Rec_67ce0* r = &recs[i];
        if (obj == 0 || r->tag == skipTag)
            continue;
        if (id->lo != DAT_004dcf00 || id->hi != DAT_004dcf04) {
            if (r->idLo != id->lo || r->idHi != id->hi)
                continue;
        }
        float rad = r->radius + s->radius;
        float dx = s->x - r->x;
        float dy = s->y - r->y;
        float dz = s->z - r->z;
        float d2 = dz * dz + dy * dy + dx * dx;
        if (!(rad * rad >= d2))
            continue;
        if (*outObj != 0 && *outObj == obj)
            continue;
        count++;
        *outObj = obj;
        float w = 1.0f / count;
        outPos->x = (r->x - outPos->x) * w + outPos->x;
        outPos->y = (r->y - outPos->y) * w + outPos->y;
        outPos->z = (r->z - outPos->z) * w + outPos->z;
    }
    return count > 0;
}
