#ifndef LA_AUDIO_H
#define LA_AUDIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	uint32_t sample_rate;
	uint32_t block_size;
} la_audio_config;

/* CONFIG FUNCTIONS */
static inline la_audio_config la_audio_config_make(uint32_t sample_rate, uint32_t block_size) {
	la_audio_config config;
	config.sample_rate = sample_rate;
	config.block_size = block_size;
	return config;
}

#ifdef __cplusplus
extern "C" {
#endif

#endif

