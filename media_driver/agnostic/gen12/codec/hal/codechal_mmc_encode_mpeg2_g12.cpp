/*
* Copyright (c) 2017-2019, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     codechal_mmc_encode_mpeg2_g12.cpp
//! \brief    Impelements the public interface for Gen12 CodecHal Media Memory Compression
//!

#include "codechal_mmc_encode_mpeg2_g12.h"

CodechalMmcEncodeMpeg2G12::CodechalMmcEncodeMpeg2G12(
    CodechalHwInterface    *hwInterface,
    void *standardState):
    CodecHalMmcStateG12(hwInterface)
{
    CODECHAL_ENCODE_FUNCTION_ENTER;

    m_mpeg2State = (CodechalEncodeMpeg2 *)standardState;
    CODECHAL_HW_ASSERT(m_mpeg2State);

#if (_DEBUG || _RELEASE_INTERNAL)
    m_compressibleId = __MEDIA_USER_FEATURE_VALUE_MMC_ENC_RECON_COMPRESSIBLE_ID;
    m_compressModeId = __MEDIA_USER_FEATURE_VALUE_MMC_ENC_RECON_COMPRESSMODE_ID;
#endif
}

MOS_STATUS CodechalMmcEncodeMpeg2G12::SetPipeBufAddr(
    PMHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams,
    PMOS_COMMAND_BUFFER cmdBuffer)
{
    MOS_STATUS eStatus = MOS_STATUS_SUCCESS;

    CODECHAL_ENCODE_FUNCTION_ENTER;

    if (m_mmcEnabled)
    {
        CODECHAL_ENCODE_CHK_STATUS_RETURN(m_osInterface->pfnGetMemoryCompressionMode(m_osInterface,
            &m_mpeg2State->m_reconSurface.OsResource, &pipeBufAddrParams->PreDeblockSurfMmcState));
    }
    else
    {
        pipeBufAddrParams->PreDeblockSurfMmcState = MOS_MEMCOMP_DISABLED;
    }
    pipeBufAddrParams->PostDeblockSurfMmcState = pipeBufAddrParams->PreDeblockSurfMmcState;

    CODECHAL_DEBUG_TOOL(
        m_mpeg2State->m_reconSurface.MmcState = pipeBufAddrParams->PreDeblockSurfMmcState;
    )
    return eStatus;
}

