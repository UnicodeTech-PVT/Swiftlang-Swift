//===--- ImageInspection.h - Image inspection routines ----------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2017 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
///
/// \file
///
/// This file includes routines that extract metadata from executable and
/// dynamic library image files generated by the Swift compiler. The concrete
/// implementations vary greatly by platform.
///
//===----------------------------------------------------------------------===//

#ifndef SWIFT_RUNTIME_SYMBOLINFO_H
#define SWIFT_RUNTIME_SYMBOLINFO_H

#include "swift/Runtime/Config.h"

#include <cstdint>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#endif

#if defined(_WIN32) && !defined(__CYGWIN__)
#include <DbgHelp.h>
#elif SWIFT_STDLIB_HAS_DLADDR
#include <dlfcn.h>
#endif

#include <optional>

namespace swift {
struct SymbolInfo {
private:
#if defined(_WIN32) && !defined(__CYGWIN__)
  const void *_symbolAddress;
  const char *_symbolName;
  const char *_moduleFileName;
  const void *_moduleBaseAddress;
#elif SWIFT_STDLIB_HAS_DLADDR
  Dl_info _info;
#endif

#if defined(_WIN32) && !defined(__CYGWIN__)
  SymbolInfo(const void *symbolAddress,
             const char *symbolName,
             const char *moduleFileName,
             const void *moduleBaseAddress)
    : _symbolAddress(symbolAddress),
      _symbolName(symbolName),
      _moduleFileName(moduleFileName),
      _moduleBaseAddress(moduleBaseAddress)
  {}

  void initializeFrom(const SymbolInfo &other) {
    _symbolAddress = other._symbolAddress;
    _symbolName = ::strdup(other._symbolName);
    _moduleFileName = ::strdup(other._moduleFileName);
    _moduleBaseAddress = other._moduleBaseAddress;
  }

  void deinitialize() {
    ::free((void *)_moduleFileName);
    ::free((void *)_symbolName);
    _moduleFileName = nullptr;
    _symbolName = nullptr;
  }
#endif

public:
#if defined(_WIN32) && !defined(__CYGWIN__)
  SymbolInfo() : _symbolName(nullptr), _moduleFileName(nullptr) {}

  SymbolInfo(const SymbolInfo &other) {
    initializeFrom(other);
  }
  SymbolInfo(SymbolInfo &&other) {
    *this = std::move(other);
  }
  ~SymbolInfo() {
    deinitialize();
  }

  SymbolInfo &operator=(const SymbolInfo &other) {
    if (this != &other) {
      deinitialize();
      initializeFrom(other);
    }

    return *this;
  }
  SymbolInfo &operator=(SymbolInfo &&other) {
    if (this != &other) {
      _symbolAddress = other._symbolAddress;
      _symbolName = other._symbolName;
      other._symbolName = nullptr;
      _moduleFileName = other._moduleFileName;
      other._moduleFileName = nullptr;
      _moduleBaseAddress = other._moduleBaseAddress;
    }

    return *this;
  }
#else
  SymbolInfo() {}
#endif

  /// Get the file name of the image where the symbol was found.
  ///
  /// The resulting C string is only valid for the lifetime of \c this.
  const char *getFilename() const;

  /// Get the base address of the image where the symbol was found.
  const void *getBaseAddress() const;

  /// Get the name of the symbol.
  ///
  /// The resulting C string is only valid for the lifetime of \c this.
  const char *getSymbolName() const;

  /// Get the address of the symbol.
  const void *getSymbolAddress() const;

  /// Look up a symbol by address.
  ///
  /// \param address The address where the symbol is located.
  ///
  /// \returns On success, an instance of \c SymbolInfo containing information
  ///   about the symbol at \a address. On failure, \c std::nullopt.
  static std::optional<SymbolInfo> lookup(const void *address);
};

} // end namespace swift

#endif