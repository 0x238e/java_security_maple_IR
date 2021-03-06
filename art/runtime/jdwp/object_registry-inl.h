/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_RUNTIME_JDWP_OBJECT_REGISTRY_INL_H_
#define ART_RUNTIME_JDWP_OBJECT_REGISTRY_INL_H_

#include "object_registry.h"

#include "obj_ptr-inl.h"

namespace art {

template<typename T>
inline ObjPtr<T> ObjectRegistry::Get(JDWP::ObjectId id, JDWP::JdwpError* error) {
  if (id == 0) {
    *error = JDWP::ERR_NONE;
    return nullptr;
  }
  return ObjPtr<T>::DownCast(InternalGet(id, error));
}

}  // namespace art

#endif  // ART_RUNTIME_JDWP_OBJECT_REGISTRY_INL_H_
