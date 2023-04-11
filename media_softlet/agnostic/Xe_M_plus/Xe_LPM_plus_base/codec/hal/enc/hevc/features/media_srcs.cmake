# Copyright (c) 2020, Intel Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.

#encode

media_include_subdirectory(preenc)

if("${HEVC_Encode_VDEnc_Supported}" STREQUAL "yes")
set(TMP_SOURCES_
    ${CMAKE_CURRENT_LIST_DIR}/encode_hevc_vdenc_feature_manager_xe_lpm_plus_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/encode_hevc_vdenc_const_settings_xe_lpm_plus_base.cpp
)

set(TMP_HEADERS_
    ${CMAKE_CURRENT_LIST_DIR}/encode_hevc_vdenc_feature_manager_xe_lpm_plus_base.h
    ${CMAKE_CURRENT_LIST_DIR}/encode_hevc_vdenc_const_settings_xe_lpm_plus_base.h
)

set(SOFTLET_ENCODE_HEVC_HEADERS_
    ${SOFTLET_ENCODE_HEVC_HEADERS_}
    ${TMP_HEADERS_}
)

set(SOFTLET_ENCODE_HEVC_SOURCES_
    ${SOFTLET_ENCODE_HEVC_SOURCES_}
    ${TMP_SOURCES_}
)

source_group( CodecHalNext\\Xe_LPM_plus_base\\Encode FILES ${TMP_SOURCES_} ${TMP_HEADERS_} )

set(TMP_SOURCES_ "")
set(TMP_HEADERS_ "")

media_add_curr_to_include_path()

endif()

set(SOFTLET_ENCODE_HEVC_PRIVATE_INCLUDE_DIRS_
    ${SOFTLET_ENCODE_HEVC_PRIVATE_INCLUDE_DIRS_}
    ${CMAKE_CURRENT_LIST_DIR}
)
