// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_0029ef40 @ 0x0029ef40
void* FUN_00263ea0(unsigned int size);

struct DirectionalLight_29ef40 {
    DirectionalLight_29ef40* FUN_002a2e70();
};
struct ProximityLight_29ef40 {
    ProximityLight_29ef40* FUN_002c3c10();
};

class LightGroup_29ef40 {
public:
    virtual void v0();
    LightGroup_29ef40* FUN_002a1140(int size);
    void FUN_002a0fc0(int index, void* cell);
};

class GridSet {
public:
    LightGroup_29ef40* grids[4];
    int width;
    int height;
    GridSet* FUN_0029ef40(int w, int h);
};

GridSet* GridSet::FUN_0029ef40(int w, int h)
{
    int i;
    void* mem;
    width = w > 1 ? w : 1;
    height = h > 1 ? h : 1;

    mem = FUN_00263ea0(0x28);
    grids[0] = mem ? ((LightGroup_29ef40*)mem)->FUN_002a1140(width) : 0;
    mem = FUN_00263ea0(0x28);
    grids[1] = mem ? ((LightGroup_29ef40*)mem)->FUN_002a1140(width) : 0;
    mem = FUN_00263ea0(0x28);
    grids[2] = mem ? ((LightGroup_29ef40*)mem)->FUN_002a1140(width) : 0;
    mem = FUN_00263ea0(0x28);
    if (mem) {
        int n = width;
        if (!(width >= height))
            n = height;
        grids[3] = ((LightGroup_29ef40*)mem)->FUN_002a1140(n);
    } else {
        grids[3] = 0;
    }
    grids[0]->v0();
    grids[1]->v0();
    grids[2]->v0();
    grids[3]->v0();

    for (i = 0; i < width; i++) {
        mem = FUN_00263ea0(0x68);
        DirectionalLight_29ef40* a = mem ? ((DirectionalLight_29ef40*)mem)->FUN_002a2e70() : 0;
        grids[0]->FUN_002a0fc0(i, a);
        mem = FUN_00263ea0(0x68);
        ProximityLight_29ef40* b = mem ? ((ProximityLight_29ef40*)mem)->FUN_002c3c10() : 0;
        grids[1]->FUN_002a0fc0(i, b);
        grids[3]->FUN_002a0fc0(i, 0);
    }
    for (i = 0; i < height; i++) {
        mem = FUN_00263ea0(0x68);
        DirectionalLight_29ef40* a = mem ? ((DirectionalLight_29ef40*)mem)->FUN_002a2e70() : 0;
        grids[2]->FUN_002a0fc0(i, a);
    }
    return this;
}
