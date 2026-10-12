// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 38/42, incomplete)
// FUN_002bd570 @ 0x002bd570
struct Tile {
    int x0;
    int y0;
    int x1;
    int y1;
    int w;
    int h;
};

int __cdecl FUN_00356c30(int value);

struct Mosaic {
    char pad0[0x54];
    int width;
    int height;
    int border;
    char pad60[0x68 - 0x60];
    int maxSize;
    int minSize;
    char pad70[0xa0 - 0x70];
    char single;
    int FUN_002bd570(Tile **tiles, int *rows, int *cols);
    int Chunk(int remaining);
};

int Mosaic::Chunk(int rem)
{
    int c = maxSize;
    if (rem >= maxSize)
        return c;
    if (rem <= minSize)
        return rem;
    if (rem != 0 && (rem & (rem - 1)) == 0)
        c = rem;
    else
        c = 1 << FUN_00356c30(rem);
    return c - border * 2;
}

int Mosaic::FUN_002bd570(Tile **tiles, int *rows, int *cols)
{
    if (single) {
        if (tiles == 0) {
            *rows = 1;
            *cols = 1;
            return 1;
        }
        (*tiles)->y0 = 0;
        (*tiles)->y1 = height;
        (*tiles)->h = height;
        (*tiles)->x0 = 0;
        (*tiles)->x1 = width;
        (*tiles)->w = width;
        return 1;
    }

    int rowCount = 0;
    int y = 0;
    Tile **row = tiles;
    while (y < height) {
        int h = Chunk(height - y);
        int y1 = y + h;
        if (tiles != 0) {
            for (int j = 0; j < *cols; j++) {
                row[0][j].y0 = y;
                row[0][j].y1 = y1;
                row[0][j].h = h;
            }
        }
        y = y1;
        rowCount++;
        row++;
    }

    int colCount = 0;
    int x = 0;
    int offset = 0;
    while (x < width) {
        int w = Chunk(width - x);
        int x1 = x + w;
        if (tiles != 0) {
            for (rowCount = 0; rowCount < *rows; rowCount++) {
                Tile *t = (Tile *)((char *)tiles[rowCount] + offset);
                t->x0 = x;
                t->x1 = x1;
                t->w = w;
            }
        }
        x = x1;
        colCount++;
        offset += sizeof(Tile);
    }

    if (tiles == 0) {
        *rows = rowCount;
        *cols = colCount;
    }
    return colCount * rowCount;
}
