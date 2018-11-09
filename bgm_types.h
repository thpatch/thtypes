/**
  * Touhou type library
  * BGM formats
  */

#pragma once
#include "warning_push.h"
#include "pragma_push.h"

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
	char fn[16]; // fn[0] == '\0' indicates the end of the array
	uint32_t track_offset;
	/* Amount of memory to allocate for the track if the BGM preloading option
	 * is set in custom.exe. In the original files, this value is always way
	 * larger than [track_size], for whatever reason - especially since the
	 * game sets the corresponding internal structure member to [track_size]
	 * before playback anyway.
	 * Only used in TH07-TH09.5. */
	uint32_t preload_size;
	/* Yes, signed. */
	int32_t intro_size;
	int32_t track_size;
	WAVEFORMATEX wfx;
	uint16_t pad;
} bgm_fmt_t;

#include "pragma_pop.h"
#include "warning_pop.h"
