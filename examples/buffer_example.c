#include <lightaudio/lightaudio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define N ((uint32_t)256)	// typical sample buffer size

void gen_data(float *arr_p, const uint32_t arr_size);

int main(void) {
	srand((unsigned)time(NULL));

	float data[N];
	gen_data(data, N);	// generate random data
	
	la_buffer buffer;
	la_buffer_init(&buffer, data, N);

	for (uint32_t i = 0; i < N; i++) {
		printf("buffer[%u] = %f\n", i, la_buffer_read(&buffer, i));
	}

	return 0;
}

void gen_data(float *arr_p, uint32_t arr_size) {
    for (uint32_t i = 0; i < arr_size; i++) {
        arr_p[i] = (float)i;   // or random: (float)rand() / RAND_MAX
    }
}

