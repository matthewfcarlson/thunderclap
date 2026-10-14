struct Vec3_10ad90 {
    float x, y, z;
};
struct List_10ad90 {
    char pad[0xc];
    int count;
    int GetItem(int i);
    bool IsSkipped(int id);
};
struct Agent_10ad90 {
    char pad[0x20];
    List_10ad90* list;
};
float FUN_0010ac60(int ex, int item, float w, Vec3_10ad90* out);

class CSeparationBehaviour {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    bool v3(Agent_10ad90* a, int ex, Vec3_10ad90* out, int p5, int p6);
    int pad4;
    float weight;
    unsigned char enabled;
};

bool CSeparationBehaviour::v3(Agent_10ad90* a, int ex, Vec3_10ad90* out, int p5, int p6) {
    int n = a->list->count;
    int i = 0;
    out->z = 0.0f;
    out->y = 0.0f;
    out->x = 0.0f;
    if (0 < n) {
        do {
            int item = a->list->GetItem(i);
            if (!a->list->IsSkipped(item) && item != ex) {
                Vec3_10ad90 tmp;
                FUN_0010ac60(ex, item, 1.0f, &tmp);
                out->x += tmp.x;
                out->y += tmp.y;
                out->z += tmp.z;
            }
            ++i;
        } while (i < n);
    }
    if (enabled) {
        float w = weight;
        out->x = w * out->x;
        out->y = w * out->y;
        out->z = w * out->z;
    }
    return true;
}
