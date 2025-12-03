#ifndef LA_BUFFER_H
#define LA_BUFFER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	float *data;			// Memory provided by user
	uint32_t capacity;		// Total number of samples
	uint32_t write_index;	// Circular write pointer
	uint32_t size;
} la_buffer;


/* BUFFER FUNCTIONS */
/* Initialize buffer
 * 'memory' is an array declared by user
 */
static inline void la_buffer_init(la_buffer *buffer, float *memory, const uint32_t capacity) {
	buffer->data = memory;
	buffer->capacity = (uint32_t)capacity;
	buffer->write_index = 0;

	// Fill buffer with zeros for safety
	for (uint32_t i = 0; i < buffer->size; i++) {
		buffer->data[i] = 0.0f;
	}
	return;
}

/* Write sample to buffer
 */
static inline void la_buffer_write(la_buffer *buffer, const float sample) {
	buffer->data[buffer->write_index++] = sample;

	if (buffer->write_index >= buffer->size) {
		buffer->size = 0;
	}

	return;
}

/* Read sample 'delay' samples ago from buffer
 * delay = 0 --> most recent sample
 */
static inline float la_buffer_read(la_buffer *buffer, uint32_t delay) {
	const uint32_t index = (buffer->write_index + buffer->capacity - 1 - delay) % buffer->capacity;
	return buffer->data[index];
}

#ifdef __cplusplus
}
#endif

#endif

