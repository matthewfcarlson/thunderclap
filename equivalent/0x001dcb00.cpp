// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 19/20, incomplete)
// FUN_001dcb00 @ 0x001dcb00
struct V3 {
    float x, y, z;
};

struct Finder {
    int FUN_001c8060(V3* box, int flag);
};

struct Holder {
    int pad;
    Finder* finder;
};

Holder* FUN_001c3d90();

struct Frame {
    V3 pos;
    V3 boxMin;
    V3 boxMax;
};

// Nudges a half-unit box around a position in +-x / +-z steps until both corners test clear.
void __stdcall FUN_001dcb00(V3* out, const V3* in)
{
    Frame f;
    float y1 = in->y + 1.0f;
    f.pos.x = in->x;
    f.pos.y = y1;
    f.pos.z = in->z;
    f.boxMin.x = in->x - 0.5f;
    f.boxMin.y = y1;
    f.boxMin.z = in->z - 0.5f;
    f.boxMax.x = in->x + 0.5f;
    f.boxMax.y = y1;
    f.boxMax.z = in->z + 0.5f;

    int i = 0;
    bool found = false;
    do {
        Holder* h = FUN_001c3d90();
        if (h->finder != 0 && h->finder->FUN_001c8060(&f.boxMin, 0) != 0) {
            h = FUN_001c3d90();
            if (h->finder != 0 && h->finder->FUN_001c8060(&f.boxMax, 0) != 0) {
                found = true;
                break;
            }
        }
        i++;
        switch (i % 9) {
        case 0:
        case 2:
            f.boxMin.z += 1.0f;
            f.boxMax.z += 1.0f;
            f.pos.z += 1.0f;
            break;
        case 1:
        case 7:
        case 8:
            f.boxMin.x -= 1.0f;
            f.boxMax.x -= 1.0f;
            f.pos.x -= 1.0f;
            break;
        case 3:
        case 4:
            f.boxMin.x += 1.0f;
            f.boxMax.x += 1.0f;
            f.pos.x += 1.0f;
            break;
        default:
            f.boxMin.z -= 1.0f;
            f.boxMax.z -= 1.0f;
            f.pos.z -= 1.0f;
            break;
        }
    } while (i <= 36);

    if (!found) {
        f.pos.x = in->x;
        f.pos.z = in->z;
    }
    out->x = f.pos.x;
    out->y = y1;
    out->z = f.pos.z;
}
