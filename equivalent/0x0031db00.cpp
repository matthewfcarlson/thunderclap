// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_42 @ 0x0031db00
#include "gen/pure3d.h"

namespace pure3d {
struct LightState_31db00 {
 char reserved[0x44];
 float red, green, blue;
 char reserved50[4];
 float average;
 char reserved58[0x20];
 unsigned color;
};

}
void pure3d::pddiBaseContext::vfunc_42(int index, int __p1) { unsigned int color = (unsigned int)__p1;

 if (index < 8) {
 (*(LightState_31db00 * *)&this->f_50)[index].color = color;
 int red = (color >> 16) & 255;
 int green = (color >> 8) & 255;
 int blue = color & 255;
 (*(LightState_31db00 * *)&this->f_50)[index].red = (float)red;
 (*(LightState_31db00 * *)&this->f_50)[index].green = (float)green;
 (*(LightState_31db00 * *)&this->f_50)[index].blue = (float)blue;
 (*(LightState_31db00 * *)&this->f_50)[index].average = (float)((red + green + blue) / 3);
 vfunc_110(index, 0);
 }
}
