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
} sprite_spec_base_t;

/* TH06 variant of the sprite coordinate structure. */
typedef struct {
	sprite_spec_base_t base;

	uint32_t register_order;
} sprite_spec06_t;

/* TH07 variant of the sprite coordinate structure. */
typedef struct {
	sprite_spec_base_t base;

	/* Factor that the Direct3D texture was scaled by in order to meet */
	/* hardware texture size requirements. ZUN's attempt to at least keep */
	/* the game running (but blurry) on 3dfx Voodoo cards despite using */
	/* textures larger than 256x256 pixels otherwise. */
	float hw_texture_scale_w;
	float hw_texture_scale_h;

	uint32_t register_order;
} sprite_spec07_t;

#pragma pack(pop)
