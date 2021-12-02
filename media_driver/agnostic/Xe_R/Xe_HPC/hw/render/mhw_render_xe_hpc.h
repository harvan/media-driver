/*===================== begin_copyright_notice ==================================

# Copyright (c) 2021, Intel Corporation

# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.

======================= end_copyright_notice ==================================*/

//!
//! \file     mhw_render_xe_hpc.h
//! \brief    Defines functions for constructing  render engine commands on Xe_XPM_plus platforms
//!

#ifndef __MHW_RENDER_XE_XPM_PLUS_H__
#define __MHW_RENDER_XE_XPM_PLUS_H__

#include "mhw_render_generic.h"
#include "mhw_render_xe_hp.h"
#include "mhw_render_hwcmd_xe_hp_base.h"
#include "mhw_mmio_g12.h"

class MhwRenderInterfaceXe_Hpc : public MhwRenderInterfaceXe_Xpm_Base
{
public:
    MhwRenderInterfaceXe_Hpc(
        MhwMiInterface          *miInterface,
        PMOS_INTERFACE          osInterface,
        MEDIA_SYSTEM_INFO       *gtSystemInfo,
        uint8_t                 newStateHeapManagerRequested) :
        MhwRenderInterfaceXe_Xpm_Base(miInterface, osInterface, gtSystemInfo, newStateHeapManagerRequested)
    {
        MHW_FUNCTION_ENTER;
    }

    virtual ~MhwRenderInterfaceXe_Hpc() { MHW_FUNCTION_ENTER; }

    virtual MOS_STATUS AddCfeStateCmd(
        PMOS_COMMAND_BUFFER             cmdBuffer,
        PMHW_VFE_PARAMS                 params);

    virtual MOS_STATUS AddComputeWalkerCmd(
        PMOS_COMMAND_BUFFER             cmdBuffer,
        PMHW_GPGPU_WALKER_PARAMS        gpgpuWalkerParams,
        PMHW_ID_ENTRY_PARAMS            interfaceDescriptorParams,
        PMOS_RESOURCE                   postsyncResource,
        uint32_t                        resourceOffset);

};
#endif
