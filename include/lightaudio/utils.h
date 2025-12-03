#ifndef LA_UTILS_H
#define LA_UTILS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline uint32_t la_clamp_int(int32_t val, int32_t min_val, int32_t max_val) {
	if (val < min_val) return min_val;
	if (val > max_val) return max_val;
	return val;
}
static inline float la_clamp_float(float val, float min_val, float max_val) {
	if (val < min_val) return min_val;
	if (val > max_val) return max_val;
	return val;
}

#ifdef __cplusplus
}
#endif

#endif

