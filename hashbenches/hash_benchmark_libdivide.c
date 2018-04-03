#include "common.h"
#include "libdivide.h"

static inline uint32_t fastmod(uint32_t x, const struct libdivide_u32_t *denom, uint32_t d) {
  return x - libdivide_u32_do(x, denom) * d;
}

int main() {
  struct libdivide_u32_t denom = libdivide_u32_gen(D);
  uint32_t seed = INITSEED;
  for(size_t i = 0; i < REPEAT; i++) {
    seed = fastmod(seed * MULTIPLIER + CONSTANTADD, &denom, D);
  }
  return seed;
}
