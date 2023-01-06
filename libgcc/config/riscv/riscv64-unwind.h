/* Copyright (C) 2017-2018 Free Software Foundation, Inc.
   Contributed by ARM Ltd.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#if !defined (RISCV64_UNWIND_H) && !defined (__ILP32__)
#define RISCV64_UNWIND_H

#define DWARF_REGNUM_RISCV64_RA_STATE 34

#define MD_POST_EXTRACT_FRAME_ADDR(context, fs, addr) \
  riscv64_post_extract_frame_addr (context, fs, addr)
#define MD_POST_FROB_EH_HANDLER_ADDR(current, target, addr) \
  riscv64_post_frob_eh_handler_addr (current, target, addr)
#define MD_FROB_UPDATE_CONTEXT(context, fs) \
  riscv64_frob_update_context (context, fs)

static inline void *
riscv64_post_extract_frame_addr (struct _Unwind_Context *context,
				 _Unwind_FrameState *fs, void *addr)
{
  return addr;
}

static inline void *
riscv64_post_frob_eh_handler_addr (struct _Unwind_Context *current,
				   struct _Unwind_Context *target
				   ATTRIBUTE_UNUSED,
				   void *handler_addr)
{
  return handler_addr;
}

static inline void
riscv64_frob_update_context (struct _Unwind_Context *context,
			     _Unwind_FrameState *fs)
{
  return;
}

#endif /* defined RISCV64_UNWIND_H && defined __ILP32__ */
