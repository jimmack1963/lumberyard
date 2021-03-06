/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <AzTest/AzTest.h>
#include <AzCore/Memory/Memory.h>
#include <AzCore/Memory/SystemAllocator.h>

namespace AssetProcessor
{
    // This is an utility class for Asset Processor Tests
    // Any gmock based fixture class can derived from this class and this will automatically do system allocation and teardown for you
    // It is important to note that if you are overriding Setup and Teardown functions of your fixture class than please call the base class functions.
    class AssetProcessorTest
        : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            AZ::AllocatorInstance<AZ::SystemAllocator>::Create();
        }

        void TearDown() override
        {
            AZ::AllocatorInstance<AZ::SystemAllocator>::Destroy();
        }
    };
}

