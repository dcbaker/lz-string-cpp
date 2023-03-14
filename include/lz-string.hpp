/*
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2021 Andrey Krasnov
 * Copyright © 2023 Dylan Baker
 *
 * C++ implementation of LZ-String, version 1.4.4
 * https://github.com/pieroxy/lz-string
 * https://github.com/dcbaker/lz-string-cpp
 */

#pragma once

namespace lzstring {

#ifdef _MSC_VER
using string = std::wstring;
#ifndef _U
#define _U(x) L##x
#endif
#else
using string = std::u16string;
#include <uchar.h>
#ifndef _U
#define _U(x) u##x
#endif
#endif

string compressToBase64(const string & input);

string decompressFromBase64(const string & input);

} // namespace lzstring
