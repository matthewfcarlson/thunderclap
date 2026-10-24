// STATUS: equivalent (tools/equiv.py level 3: 3200 inputs, branch coverage 0/0)
// FUN_00341bd0 @ 0x00341bd0
struct Twiddle_341bd0 {
    float pad0;
    float a;
    float b;
};

// In-place 32-point butterfly pass over the buffer m: the sums and differences of the four 8-float
// rows are combined with the two twiddle factors and written back. Every intermediate the original
// rounds to float through a stack slot is a hulk_fslot here (t<n>_<frame offset>): MSVC 7.1 would keep
// it unrounded in an x87 register, so under the verification compiler the typedef forces the store.
#if defined(_MSC_VER) && !defined(__clang__)
typedef volatile float hulk_fslot; // forces the store-and-reload MSVC 7.1 would otherwise skip
#else
typedef float hulk_fslot;
#endif
// equiv-conv: FUN_00341bd0 eax ecx
void FUN_00341bd0(float *m, Twiddle_341bd0 *c)
{
    float ka = c->a;
    float kb = c->b;
    // the odd rows' sums the original keeps in x87 registers (MSVC 7.1 would share and round them)
    double s1_17 = m[1] + m[17];
    double s3_19 = m[3] + m[19];
    double s5_21 = m[5] + m[21];
    double s7_23 = m[23] + m[7];
    hulk_fslot t1_08 = (m[0] - m[16]);
    hulk_fslot t2_04 = (m[1] - m[17]);
    hulk_fslot t3_10 = (m[9] + m[25]);
    hulk_fslot t4_00 = (m[8] - m[24]);
    hulk_fslot t5_0c = (m[9] - m[25]);
    hulk_fslot t6_54 = ((m[24] + m[8]) + (m[0] + m[16]));
    hulk_fslot t7_64 = (t3_10 + s1_17);
    hulk_fslot t8_3c = ((m[0] + m[16]) - (m[24] + m[8]));
    hulk_fslot t9_44 = (s1_17 - t3_10);
    hulk_fslot t10_60 = (t1_08 - t5_0c);
    hulk_fslot t11_78 = (t4_00 + t2_04);
    hulk_fslot t12_50 = (t5_0c + t1_08);
    hulk_fslot t13_28 = (t2_04 - t4_00);
    hulk_fslot t14_08 = (m[2] - m[18]);
    hulk_fslot t15_04 = (m[3] - m[19]);
    hulk_fslot t16_10 = (m[11] + m[27]);
    hulk_fslot t17_00 = (m[10] - m[26]);
    hulk_fslot t18_0c = (m[11] - m[27]);
    hulk_fslot t19_74 = ((m[26] + m[10]) + (m[18] + m[2]));
    hulk_fslot t20_84 = (t16_10 + s3_19);
    hulk_fslot t21_20 = ((m[18] + m[2]) - (m[26] + m[10]));
    hulk_fslot t22_24 = (s3_19 - t16_10);
    hulk_fslot t23_68 = (((t14_08 - t18_0c) * ((ka * kb) + kb)) - ((t17_00 + t15_04) * (ka * kb)));
    hulk_fslot t24_88 = (((t17_00 + t15_04) * ((ka * kb) + kb)) + ((t14_08 - t18_0c) * (ka * kb)));
    hulk_fslot t25_80 = (((t18_0c + t14_08) * (ka * kb)) - ((t15_04 - t17_00) * ((ka * kb) + kb)));
    hulk_fslot t26_30 = (((t18_0c + t14_08) * ((ka * kb) + kb)) + ((t15_04 - t17_00) * (ka * kb)));
    hulk_fslot t27_08 = (m[4] - m[20]);
    hulk_fslot t28_04 = (m[5] - m[21]);
    hulk_fslot t29_10 = (m[13] + m[29]);
    hulk_fslot t30_00 = (m[12] - m[28]);
    hulk_fslot t31_0c = (m[13] - m[29]);
    hulk_fslot t32_5c = ((m[28] + m[12]) + (m[20] + m[4]));
    hulk_fslot t33_6c = (t29_10 + s5_21);
    hulk_fslot t34_4c = ((m[20] + m[4]) - (m[28] + m[12]));
    hulk_fslot t35_34 = (s5_21 - t29_10);
    hulk_fslot t36_38 = (((t27_08 - t31_0c) - (t30_00 + t28_04)) * ka);
    hulk_fslot t37_40 = (((t30_00 + t28_04) + (t27_08 - t31_0c)) * ka);
    hulk_fslot t38_48 = (((t28_04 - t30_00) + (t31_0c + t27_08)) * ka);
    hulk_fslot t39_58 = (((t28_04 - t30_00) - (t31_0c + t27_08)) * ka);
    hulk_fslot t40_08 = (m[6] - m[22]);
    hulk_fslot t41_04 = (m[7] - m[23]);
    hulk_fslot t42_10 = (m[31] + m[15]);
    hulk_fslot t43_00 = (m[14] - m[30]);
    hulk_fslot t44_0c = (m[15] - m[31]);
    hulk_fslot t45_7c = ((m[14] + m[30]) + (m[6] + m[22]));
    hulk_fslot t46_8c = (t42_10 + s7_23);
    hulk_fslot t47_2c = ((m[6] + m[22]) - (m[14] + m[30]));
    hulk_fslot t48_70 = (s7_23 - t42_10);
    hulk_fslot t49_1c = (((t40_08 - t44_0c) * (ka * kb)) - ((t43_00 + t41_04) * ((ka * kb) + kb)));
    hulk_fslot t50_14 = (((t40_08 - t44_0c) * ((ka * kb) + kb)) + ((t43_00 + t41_04) * (ka * kb)));
    hulk_fslot t51_00 = (((t44_0c + t40_08) * ((ka * kb) + kb)) - ((t41_04 - t43_00) * (ka * kb)));
    hulk_fslot t52_18 = (t13_28 - t39_58);
    hulk_fslot t53_08 = (t38_48 + t12_50);
    hulk_fslot t54_04 = (t39_58 + t13_28);
    hulk_fslot t55_10 = (t26_30 - (((t41_04 - t43_00) * ((ka * kb) + kb)) + ((t44_0c + t40_08) * (ka * kb))));
    hulk_fslot t56_00 = (t51_00 + t25_80);
    hulk_fslot t57_0c = ((((t41_04 - t43_00) * ((ka * kb) + kb)) + ((t44_0c + t40_08) * (ka * kb))) + t26_30);
    m[24] = ((t25_80 - t51_00) + (t12_50 - t38_48));
    m[25] = (t55_10 + t52_18);
    m[26] = ((t12_50 - t38_48) - (t25_80 - t51_00));
    m[27] = (t52_18 - t55_10);
    m[28] = (t53_08 - t57_0c);
    m[29] = (t56_00 + t54_04);
    m[30] = (t57_0c + t53_08);
    m[31] = (t54_04 - t56_00);
    hulk_fslot t58_08 = (t10_60 - t36_38);
    hulk_fslot t59_04 = (t11_78 - t37_40);
    hulk_fslot t60_10 = (t50_14 + t24_88);
    hulk_fslot t61_00 = (t23_68 - t49_1c);
    hulk_fslot t62_0c = (t24_88 - t50_14);
    m[16] = ((t49_1c + t23_68) + (t36_38 + t10_60));
    m[17] = (t60_10 + (t37_40 + t11_78));
    m[18] = ((t36_38 + t10_60) - (t49_1c + t23_68));
    m[19] = ((t37_40 + t11_78) - t60_10);
    m[20] = (t58_08 - t62_0c);
    m[21] = (t61_00 + t59_04);
    m[22] = (t62_0c + t58_08);
    m[23] = (t59_04 - t61_00);
    hulk_fslot t63_14 = (((t21_20 - t48_70) - (t47_2c + t22_24)) * ka);
    hulk_fslot t64_00 = (((t48_70 + t21_20) - (t22_24 - t47_2c)) * ka);
    hulk_fslot t65_0c = (((t22_24 - t47_2c) + (t48_70 + t21_20)) * ka);
    hulk_fslot t66_18 = (t34_4c + t9_44);
    hulk_fslot t67_08 = (t35_34 + t8_3c);
    hulk_fslot t68_04 = (t9_44 - t34_4c);
    m[8] = (t63_14 + (t8_3c - t35_34));
    m[9] = ((((t21_20 - t48_70) + (t47_2c + t22_24)) * ka) + t66_18);
    m[10] = ((t8_3c - t35_34) - t63_14);
    m[11] = (t66_18 - (((t21_20 - t48_70) + (t47_2c + t22_24)) * ka));
    m[12] = (t67_08 - t65_0c);
    m[13] = (t64_00 + t68_04);
    m[14] = (t65_0c + t67_08);
    m[15] = (t68_04 - t64_00);
    hulk_fslot t69_08 = (t6_54 - t32_5c);
    hulk_fslot t70_04 = (t7_64 - t33_6c);
    hulk_fslot t71_10 = (t46_8c + t20_84);
    hulk_fslot t72_00 = (t19_74 - t45_7c);
    hulk_fslot t73_0c = (t20_84 - t46_8c);
    m[0] = ((t45_7c + t19_74) + (t32_5c + t6_54));
    m[1] = (t71_10 + (t33_6c + t7_64));
    m[2] = ((t32_5c + t6_54) - (t45_7c + t19_74));
    m[3] = ((t33_6c + t7_64) - t71_10);
    m[4] = (t69_08 - t73_0c);
    m[5] = (t72_00 + t70_04);
    m[6] = (t73_0c + t69_08);
    m[7] = (t70_04 - t72_00);

}
