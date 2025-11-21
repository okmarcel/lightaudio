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
} la_buffer;

/* Initialize buffer
 * 'memory' is an array declared by user
 */
inline void la_buffer_init(la_buffer *buffer, const float *memory, const uint32_t capacity);

/* Write sample to buffer
 */
inline void la_buffer_write(la_buffer *buffer, const float sample);

/* Read sample 'delay' samples ago from buffer
 * delay = 0 --> most recent sample
 */
inline float la_buffer_read(la_buffer *buffer, uint32_t delay);

#ifdef __cplusplus
}
#endif

#endif

