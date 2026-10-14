// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// ImageSelector::vfunc_20 @ 0x000ee0c0
struct Item { virtual void vfunc_0(); };
struct Receiver { void FUN_000f8b90(int value); };
struct ImageSelector {
 virtual void vfunc_0();
 char pad[0x150-4];
 Item* cells[8][8];
 char gap250[0x40];
 int count;
 int field294;
 int width;
 char gap[8];
 int selected;
 int current;
 Receiver* receiver;
 void vfunc_20(Item* item, bool select);
};
void ImageSelector::vfunc_20(Item* item, bool select) {
 if (!item) return;
 int row = -1, col = -1;
 for (int r=0;r<8;++r) {
  for (int c=0;c<8;++c) {
   if (!cells[r][c]) {
    cells[r][c]=item;
    item->vfunc_0();
    row=r; col=c;
    break;
   }
  }
 }
 if (row == -1 || col == -1) return;
 if (select) {
  int index=width*row+col;
  current=index;
  selected=index;
  if (receiver) receiver->FUN_000f8b90(index);
  vfunc_0();
 }
 ++count;
}
