#include "lightaudio/la_buffer.h"

inline void la_buffer_init(la_buffer *buffer, const float *memory, const uint32_t capacity) {
	buffer->data = memory;
	buffer->capacity = capacity;
	buffer->write_index = 0;

	// Fill buffer with zeros for safety
	for (uint32_t i = 0; i < size; i++) {
		buffer->data[i] = 0.0f;
	}

	return;
}

inline void la_buffer_write(la_buffer *buffer, const float sample) {
	buffer->data[buffer->write_index++] = sample;

	if (buffer->write_index >= buffer->size) {
		buffer->size = 0;
	}

	return;
}

inline float la_buffer_read(la_buffer *buffer, uint32_t delay) {
	const uint32_t index = (buffer->write_index + buffer->capacity - 1 - delay) % buffer->capacity;
	return buffer->data[index];
}

