/*
 * Copyright (c) 2000, 2018, Oracle and/or its affiliates. All rights reserved.
 * Copyright (c) 2012, 2013 SAP SE. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef OS_CPU_BSD_PPC_VM_THREAD_BSD_PPC_HPP
#define OS_CPU_BSD_PPC_VM_THREAD_BSD_PPC_HPP

 private:

  void pd_initialize() {
    _anchor.clear();
  }

  // The `last' frame is the youngest Java frame on the thread's stack.
  frame pd_last_frame();

 public:

  void set_base_of_stack_pointer(intptr_t* base_sp) {}
  intptr_t* base_of_stack_pointer() { return NULL; }
  void record_base_of_stack_pointer() {}

  // These routines are only used on cpu architectures that
  // have separate register stacks (Itanium).
  static bool register_stack_overflow() { return false; }
  static void enable_register_stack_guard() {}
  static void disable_register_stack_guard() {}

  bool pd_get_top_frame_for_signal_handler(frame* fr_addr, void* ucontext, bool isInJava);

  bool pd_get_top_frame_for_profiling(frame* fr_addr, void* ucontext, bool isInJava);

#endif // OS_CPU_BSD_PPC_VM_THREAD_BSD_PPC_HPP
