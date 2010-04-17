/* vim:ts=8:sts=8:sw=4:noai:noexpandtab
 *
 * MD5 hashing algorithm.
 *
 * MD5 original source GNU C Library:
 * Includes functions to compute MD5 message digest of files or memory blocks
 * according to the definition of MD5 in RFC 1321 from April 1992.
 *
 * Copyright (C) 1995, 1996, 2001, 2003 Free Software Foundation, Inc.
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this file; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#if !defined (__PGM_FRAMEWORK_H_INSIDE__) && !defined (PGM_COMPILATION)
#       error "Only <framework.h> can be included directly."
#endif

#ifndef __PGM_MD5_H__
#define __PGM_MD5_H__

#include <pgm/types.h>

PGM_BEGIN_DECLS

struct pgm_md5_t
{
	uint32_t	A;
	uint32_t	B;
	uint32_t	C;
	uint32_t	D;

	uint32_t	total[2];
	uint32_t	buflen;
	char		buffer[128] __attribute__ ((__aligned__ (__alignof__ (uint32_t))));
};

PGM_GNUC_INTERNAL void pgm_md5_init_ctx (struct pgm_md5_t*);
PGM_GNUC_INTERNAL void pgm_md5_process_bytes (struct pgm_md5_t*, const void*, size_t);
PGM_GNUC_INTERNAL void* pgm_md5_finish_ctx (struct pgm_md5_t*, void*);

PGM_END_DECLS

#endif /* __PGM_MD5_H__ */

