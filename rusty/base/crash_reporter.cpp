// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// that can be found in the LICENSE file.

#include "rusty/base/crash_reporter.h"

namespace rusty {

void raiseSegmentFault() {
  volatile int* a = (int*)(nullptr);
  *a = 1;
}

}  // namespace rusty