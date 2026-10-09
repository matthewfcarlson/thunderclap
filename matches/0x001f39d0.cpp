static float gValue;
static const float gScale = 0.01f;
extern void __cdecl Apply(int, float);
class Obj {
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
void Obj::Update(float x) {
    gValue = x;
    if (flag == 0) {
        int i = 0;
        if (count > 0) {
            int* p = (int*)((char*)this + 8);
            do {
                int v = *p;
                if (v != at8c && v != skip) {
                    int q = *(int*)(v + 4);
                    if (q)
                        Apply(q, gValue * gScale);
                }
                ++i;
                ++p;
            } while (i < count);
        }
    }
}