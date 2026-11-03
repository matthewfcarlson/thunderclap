#include "gen/owners.h"
class Cell {
  public:
    char pad[8];
};
class Grid {
  public:
    char pad[12];
    char dirty;
    char pad2[107];
    Cell cells[100];
    char Put(int x, int y, int z, int v);
};
char Grid::Put(int x, int y, int z, int v) {
    if (x < 0 || x >= 2 || y < 0 || y >= 2 || z < 0 || z >= 3)
        return 0;
    ((owners::Target_b10a0 *)&(cells[(z + 3 * (y + 2 * x + 10))]))->FUN_000b10a0(0, (const void *)(hulk_uintptr)(int)v);
    dirty = 1;
    return 1;
}