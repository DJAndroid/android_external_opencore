/* ------------------------------------------------------------------
 * Copyright (C) 1998-2009 PacketVideo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 * -------------------------------------------------------------------
 */
#ifndef PVMF_OMX_VIDEODEC_FACTORY_H_INCLUDED
#define PVMF_OMX_VIDEODEC_FACTORY_H_INCLUDED

#ifndef OSCL_BASE_H_INCLUDED
#include "oscl_base.h"
#endif

#ifndef OSCL_SCHEDULER_AO_H_INCLUDED
#include "oscl_scheduler_ao.h"
#endif

// Forward declaration
class PVMFNodeInterface;

#define KPVMFOMXVideoDecNodeUuid PVUuid(0x8f39e9d1,0x1232,0x4394,0xad,0x85,0x43,0xd3,0x29,0x11,0x9a,0x4a)
/**
 * PVMFOMXVideoDecNodeFactory Class
 *
 * a singleton class which instantiates and provides
 * access to OMX video decoder node. It returns a PVMFNodeInterface
 * reference, the interface class of the PVMFVideoDecNode.
 *
 * The client is expected to contain and maintain a pointer to the instance created
 * while the node is active.
 */
class PVMFOMXVideoDecNodeFactory
{
    public:
        /**
         * Creates an instance of a PVMFOMXVideoDecNode. If the creation fails, this function will leave.
         *
         * @param aPriority The active object priority for the node. Default is standard priority if not specified
         * @returns A pointer to an instance of PVMFOMXVideoDecNode as PVMFNodeInterface reference or leaves if instantiation fails
         **/
        OSCL_IMPORT_REF static PVMFNodeInterface* CreatePVMFOMXVideoDecNode(int32 aPriority = OsclActiveObject::EPriorityNominal);

        /**
         * Deletes an instance of PVMFOMXVideoDecNode
         * and reclaims all allocated resources.  An instance can be deleted only in
         * the idle state. An attempt to delete in any other state will fail and return false.
         *
         * @param aNode The PVMFAVCDecNode instance to be deleted
         * @returns A status code indicating success or failure of deletion
         **/
        OSCL_IMPORT_REF static bool DeletePVMFOMXVideoDecNode(PVMFNodeInterface* aNode);
};

#endif // PVMF_OMX_VIDEODEC_FACTORY_H_INCLUDED

