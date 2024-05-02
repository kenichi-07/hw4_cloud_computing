#include "cpu_features.h"

CPUFeatures g_cpu_features;

void _get_cpu_features() {
    // Simulate detection logic
    g_cpu_features.has_neon = true;  // Assume NEON is available on ARM64
    g_cpu_features.has_sse = false;  // SSE is not available on ARM
}
