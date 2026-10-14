// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 18/19, incomplete)
// FUN_00203890 @ 0x00203890
struct Object {
 void FUN_00203870(const char* name);
 void FUN_00203890(int index);
};
void Object::FUN_00203890(int index) {
 switch (index) {
 case 0: FUN_00203870("hulk_australia"); break;
 case 1: FUN_00203870("grey_hulk"); break;
 case 2: FUN_00203870("joefixit"); break;
 case 3: FUN_00203870("abomination_ashulk"); break;
 case 4: FUN_00203870("banner_savage"); break;
 case 5: FUN_00203870("hulk_canada"); break;
 case 6: FUN_00203870("hulk_us"); break;
 case 7: FUN_00203870("hulk_uk"); break;
 case 8: FUN_00203870("hulk_france"); break;
 case 9: FUN_00203870("hulk_german"); break;
 case 10: FUN_00203870("hulk_italy"); break;
 case 11: FUN_00203870("hulk_spain"); break;
 case 12: FUN_00203870("hulk_japan"); break;
 }
}
