// STATUS: equivalent (tools/equiv.py level 3: 417 inputs, branch coverage 79/80, incomplete)
// FUN_001ad8c0 @ 0x001ad8c0
extern "C" double sqrt(double);
struct V3 {
    float x, y, z;
    void FUN_0022d180();
};
struct Seg {
    V3 a, b;
    float FUN_0022ff50(const V3* p);
};
struct Node {
    int nbr[3];
    char pad0c[3];
    unsigned char b0f;
};
struct Pool {
    Node* FUN_001b5800(int idx);
    V3* FUN_001b5a20(V3* out, int idx);
    char FUN_001b65f0(int a, int k);
};
char FUN_001ad730(int idx, struct Graph* g);
void FUN_000658d0(V3* c, V3* q, V3* p, float* out);
struct Graph {
    Pool* p0;
    char pad4[4];
    unsigned int f8;
    int F(V3* Q, V3* P, int c, float minD, float maxD, int a6, char maximize, char useDist, int n, int a10,
          char fallback, float a12, float a13);
};
int Graph::F(V3* Q, V3* P, int c, float minD, float maxD, int a6, char maximize, char useDist, int n, int a10,
             char fallback, float a12, float a13) {
    // These are adjacent because the projection routine receives a pointer into this workspace.
    struct ProjectionWorkspace {
        float value;
        float secondError;
        V3 position;
    } workspace;
    workspace.value = 0;
    workspace.secondError = 0;
    Node* initial = p0->FUN_001b5800(c);
    Pool* pool = p0;
    int bestIdx = c, runnerUp = 0;
    float bestDistance = 0, secondDistance = 0;
    float bestDot = 0, secondDot = 0;
    float bestError = 0;
    V3 displacement, direction, finalTemp;
    Seg segment;
    if (!initial)
        return 0;
    V3* center = pool->FUN_001b5a20(&workspace.position, c);
    float dx = center->x - P->x;
    float dy = center->y - P->y;
    float dz = center->z - P->z;
    bestDistance = (float)sqrt(dz * dz + dy * dy + dx * dx);
    direction.x = P->x - Q->x;
    direction.y = P->y - Q->y;
    direction.z = P->z - Q->z;
    pool->FUN_001b5a20(&displacement, c);
    displacement.FUN_0022d180();
    direction.FUN_0022d180();
    bestDot = displacement.z * direction.z + displacement.y * direction.y + direction.x * displacement.x;
    for (int pass = 0; pass < n; ++pass) {
        Node* neighbors;
        if (pass > 0 && bestIdx == c && runnerUp != 0)
            neighbors = p0->FUN_001b5800(runnerUp);
        else
            neighbors = p0->FUN_001b5800(bestIdx);
        for (int slot = 0; slot < 3; ++slot) {
            int candidate = neighbors->nbr[slot];
            if (candidate == -1) {
                if (!p0->FUN_001b65f0(c, slot))
                    continue;
                candidate = neighbors->nbr[slot];
                if (candidate == -1)
                    continue;
            }
            Node* node = p0->FUN_001b5800(candidate);
            if (!node) {
                neighbors->nbr[slot] = -1;
                continue;
            }
            if (candidate == c)
                continue;
            if (node->b0f > f8 && !FUN_001ad730(candidate, this))
                continue;
            V3* position = pool->FUN_001b5a20(&workspace.position, candidate);
            displacement.x = position->x;
            displacement.y = position->y;
            float z = position->z;
            float vx = displacement.x - P->x;
            float vy = displacement.y - P->y;
            float vz = z - P->z;
            float distance = (float)sqrt(vz * vz + vy * vy + vx * vx);
            displacement.x -= Q->x;
            displacement.y -= Q->y;
            displacement.z = z - Q->z;
            displacement.FUN_0022d180();
            direction.FUN_0022d180();
            float dot =
                displacement.z * direction.z + displacement.y * direction.y + direction.x * displacement.x;
            if (distance < minD || distance > maxD)
                continue;
            segment.a = displacement;
            segment.b = *Q;
            float segmentDistance = segment.FUN_0022ff50(P);
            if (a13 != 0.0f && segmentDistance < a13)
                continue;
            if (a12 != 0.0f) {
                V3* original = pool->FUN_001b5a20(&finalTemp, candidate);
                FUN_000658d0(original, Q, P, &workspace.value);
                float difference = workspace.value - a12;
                unsigned int bits = *(unsigned int*)&difference & 0x7fffffff;
                float error = *(float*)&bits;
                if (bestError == 0.0f || error < bestError) {
                    bestError = error;
                    bestIdx = candidate;
                    continue;
                }
                if (runnerUp != 0 && !(error < workspace.secondError))
                    continue;
                workspace.secondError = error;
                runnerUp = candidate;
                continue;
            }
            float key = useDist ? distance : dot;
            float* best = useDist ? &bestDistance : &bestDot;
            float* second = useDist ? &secondDistance : &secondDot;
            if (maximize) {
                if (key > *best) {
                    *best = key;
                    bestIdx = candidate;
                    continue;
                }
                if (runnerUp != 0 && !(key > *second))
                    continue;
            } else {
                if (key < *best) {
                    *best = key;
                    bestIdx = candidate;
                    continue;
                }
                if (runnerUp != 0 && !(key < *second))
                    continue;
            }
            *second = key;
            runnerUp = candidate;
        }
    }
    int result = (n <= 0 || bestIdx == c) && fallback ? runnerUp : bestIdx;
    V3* chosen = pool->FUN_001b5a20(&finalTemp, result);
    segment.a = *chosen;
    segment.b = *Q;
    segment.FUN_0022ff50(P);
    return result;
}