/**
  * Touhou type library
  * BGM formats
  */

#pragma once

#include <stdint.h>

#pragma pack(push, 1)

#ifndef _WAVEFORMATEX_
#define _WAVEFORMATEX_

/*
 *  extended waveform format structure used for all non-PCM formats. this
 *  structure is common to all non-PCM formats.
 */
typedef struct tWAVEFORMATEX
{
	uint16_t wFormatTag;      /* format type */
	uint16_t nChannels;       /* number of channels (i.e. mono, stereo...) */
	uint32_t nSamplesPerSec;  /* sample rate */
	uint32_t nAvgBytesPerSec; /* for buffer estimation */
	uint16_t nBlockAlign;     /* block size of data */
	uint16_t wBitsPerSample;  /* number of bits per sample of mono data */
	uint16_t cbSize;          /* the count in bytes of the size of */
	                          /* extra information (after cbSize)  */
} WAVEFORMATEX, *PWAVEFORMATEX, *NPWAVEFORMATEX, *LPWAVEFORMATEX;

#endif /* _WAVEFORMATEX_ */

/* .pos file format, used in TH06 and Kioh Gyoku. Values are in samples. */
typedef struct {
	uint32_t loop_start;
	uint32_t loop_end;
} bgm_pos_t;

/* Single track in thbgm.fmt, used from TH07 on. Values are in bytes. */
typedef struct {
	const char fn[16]; // fn[0] == '\0' indicates the end of the array
	uint32_t track_offset;
	uint32_t unknown;
	uint32_t intro_size;
	uint32_t track_size;
	WAVEFORMATEX wfx;
	uint16_t pad;
} bgm_fmt_t;

#pragma pack(pop)