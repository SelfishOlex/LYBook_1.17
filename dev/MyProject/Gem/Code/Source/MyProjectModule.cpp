

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include <MyProjectSystemComponent.h>
#include <MyComponent.h>
#include <OscillatorComponent.h>
#include <MySpawnerComponent.h>
#include <StartingMapSystemComponent.h>
#include <TransformSyncComponent.h>
#include <MyUIStatusComponents.h>
#include <MyScriptHelperComponent.h>
#include <MyScriptSystemComponent.h>
#include <ScriptCanvas/MyNodeLibrary.h>
#include <LargeWorld/PlayerAoIComponent.h>
#include <LargeWorld/PointOfInterestComponent.h>

namespace MyProject
{
    class MyProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MyProjectModule, "{CA6512E1-C99B-40DD-AA87-6C9F1CA6DE2D}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MyProjectModule, AZ::SystemAllocator, 0);

        MyProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                MyProjectSystemComponent::CreateDescriptor(),
                MyComponent::CreateDescriptor(),
                OscillatorComponent::CreateDescriptor(),
                MySpawnerComponent::CreateDescriptor(),
                StartingMapSystemComponent::CreateDescriptor(),
                TransformSyncComponent::CreateDescriptor(),
                MyScriptHelperComponent::CreateDescriptor(),

                MyUIForwardComponent::CreateDescriptor(),
                MyUIBackwardComponent::CreateDescriptor(),
                MyUIStrafeLeftComponent::CreateDescriptor(),
                MyUIStrafeRightComponent::CreateDescriptor(),

                MyScriptSystemComponent::CreateDescriptor(),

                PlayerAoIComponent::CreateDescriptor(),
                PointOfInterestComponent::CreateDescriptor(),

                // enabling interest management
                AzFramework::InterestManagerComponent::CreateDescriptor(),
            });

            const auto desc =
                MyNodeLibrary::GetComponentDescriptors();
            m_descriptors.insert(m_descriptors.end(),
                desc.begin(), desc.end());
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MyProjectSystemComponent>(),
                azrtti_typeid<StartingMapSystemComponent>(),
                azrtti_typeid<MyScriptSystemComponent>(),
                azrtti_typeid<AzFramework::InterestManagerComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(MyProject_8637e686e8394c85a4823a27ffa57418, MyProject::MyProjectModule)
