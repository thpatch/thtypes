/**
  * Touhou type library
  * Internal sprite structures
  */

#pragma once

#include <stdint.h>

#pragma pack(push, 1)

struct rect_t {
	float left;
	float top;
	float right;
	float bottom;
};

/* Internal structure describing the coordinates of a single sprite within a
   texture, generated from the ANM header. */
typedef struct {
	uint32_t texture_slot;

	/* Pixel coordinates of the sprite within the texture */
	rect_t abs;

	/* Width and height of the containing THTX */
	float thtx_h;
	float thtx_w;

	/* Relative coordinates of the sprite within the texture. */
	/* Can exceed 1 and therefore wrap around. */
	rect_t rel;

	/* Absolute dimensions of the sprite */
	float abs_h;
	float abs_w;

	/* How many sprites were registered before this one? */
	uint32_t register_order;
} sprite_spec06_t;

#pragma pack(pop)
