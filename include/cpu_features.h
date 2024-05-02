#ifndef CPU_FEATURES_H
#define CPU_FEATURES_H

struct CPUFeatures {
    bool has_neon;
    bool has_sse;
};

extern CPUFeatures g_cpu_features;

void _get_cpu_features();

#endif // CPU_FEATURES_H
