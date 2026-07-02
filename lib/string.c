#include <types.h>

void *memset(void *s, int c, size_t n)
{
	size_t i;
	
	uint8_t * mem_ptr = (uint8_t *)s;
	uint8_t mem_val = (uint8_t)(c & 0xff);

	for(i=0;i<n;i++) {
		*mem_ptr = mem_val;
		mem_ptr++;
	}

	return s;
}

void *memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	uint8_t *dest_prime;
	uint8_t *src_prime;

	dest_prime = (uint8_t *)dest;
	src_prime = (uint8_t *)src;

	for(i=0;i<n;i++) {
		*dest_prime++ = *src_prime++;
	}

	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	uint8_t *dest_prime;
	uint8_t *src_prime;

	uintptr_t dest_int = (uintptr_t)dest;
	uintptr_t src_int = (uintptr_t)src;

	size_t i;

	if(src_int == dest_int || n==0) {
		return dest;
	} else if((src_int < dest_int) && (dest_int < (src_int+n))) {
		dest_prime = (uint8_t *)((dest_int + n) - 1);
		src_prime = (uint8_t *)((src_int + n) - 1);
		
		for(i=0;i<n;i++) {
			*dest_prime-- = *src_prime--;
		}

		return dest;		
	} else {
		return memcpy(dest, src, n);
	}
}

int memcmp(const void *a, const void *b, size_t n)
{
	size_t i;

	const uint8_t *x = (const uint8_t *)a;
	const uint8_t *y = (const uint8_t *)b;

	for(i=0; i<n; i++) {
		if(x[i]!=y[i]) {
			return (int)x[i] - (int)y[i];
		}
	}

	return 0;
}
