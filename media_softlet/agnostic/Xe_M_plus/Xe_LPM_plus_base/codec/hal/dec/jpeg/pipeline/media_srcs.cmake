# Copyright (c) 2021-2022, Intel Corporation
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

if(${AVC_Decode_Supported} STREQUAL "yes")
set(TMP_SOURCES_
    ${CMAKE_CURRENT_LIST_DIR}/decode_jpeg_pipeline_xe_lpm_plus_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/decode_jpeg_pipeline_adapter_xe_lpm_plus_base.cpp
)

set(TMP_HEADERS_
    ${CMAKE_CURRENT_LIST_DIR}/decode_jpeg_pipeline_xe_lpm_plus_base.h
    ${CMAKE_CURRENT_LIST_DIR}/decode_jpeg_pipeline_adapter_xe_lpm_plus_base.h
)

set(SOURCES_
    ${SOURCES_}
    ${TMP_SOURCES_}
)

set(HEADERS_
    ${HEADERS_}
    ${TMP_HEADERS_}
)

set(CODEC_SOURCES_
    ${CODEC_SOURCES_}
    ${TMP_SOURCES_}
)

set(CODEC_HEADERS_
    ${CODEC_HEADERS_}
    ${TMP_HEADERS_}
)

source_group( CodecHalNext\\Xe_M_plus\\Decode FILES ${TMP_SOURCES_} ${TMP_HEADERS_})
set(TMP_SOURCES_ "")
set(TMP_HEADERS_ "")
endif()

media_add_curr_to_include_path()
