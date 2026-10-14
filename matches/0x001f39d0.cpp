static float gValue_1f39d0;
static const float gScale_1f39d0 = 0.01f;
extern void __cdecl Apply(int, float);
class Obj_1f39d0 {
  public:
    char p0[8];
    int* items[1];
    char p1[0x88 - 0x0c];
    int count;
    int at8c;
    char p2[0xc0 - 0x90];
    int skip;
    char p3[0x32c - 0xc4];
    int flag;
    void Update(float);
};
void Obj_1f39d0::Update(float x) {
    gValue_1f39d0 = x;
    if (flag == 0) {
        int i = 0;
        if (count > 0) {
            int* p = (int*)((char*)this + 8);
            do {
                int v = *p;
                if (v != at8c && v != skip) {
                    int q = *(int*)(v + 4);
                    if (q)
                        Apply(q, gValue_1f39d0 * gScale_1f39d0);
                }
                ++i;
                ++p;
            } while (i < count);
        }
    }
}