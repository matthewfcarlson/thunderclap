// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::BlendFrameController::vfunc_19 @ 0x002852a0
namespace pure3d {
struct Animation { char pad[0x18]; unsigned char enabled; };
struct BlendEntry { unsigned int value; unsigned int mode; unsigned int unused; Animation* animation; char pad[0x1c]; };
struct BlendFrameController {
  virtual void vfunc_0();
  char pad[0x20];
  unsigned int defaultValue;
  unsigned int count;
  char pad2[0x1c];
  BlendEntry entries[1];
  unsigned int vfunc_19();
};
unsigned int BlendFrameController::vfunc_19() {
  if (count != 0) {
    BlendEntry& entry = entries[count - 1];
    if (entry.mode != 0) return entry.value;
    if (entry.animation != 0) return entry.animation->enabled == 0;
  }
  return defaultValue;
}
}