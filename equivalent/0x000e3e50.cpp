// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 8/8)
// TextTable::vfunc_12 @ 0x000e3e50
class TextTable {
public:
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual unsigned int vfunc_12(unsigned int action, unsigned int unused);
 virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
 virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
 char padding[0x495c - 4];
 unsigned int total;
 char gap[4];
 unsigned int position;
 unsigned int selected;
};
unsigned int TextTable::vfunc_12(unsigned int action, unsigned int unused)
{
 if (action == 4) {
  unsigned int oldSelected = selected;
  if (oldSelected == total - 1) return oldSelected & 0xffffff00;
  unsigned int newPosition = position + 1;
  selected = oldSelected + 1;
  position = newPosition;
  return (oldSelected + 1 & 0xffffff00) | 1;
 }
 if (action == 0) {
  unsigned int oldPosition = position;
  if (oldPosition == 0) return 0;
  position = oldPosition - 1;
  --selected;
  return ((oldPosition - 1) & 0xffffff00) | 1;
 }
 return action & 0xffffff00;
}