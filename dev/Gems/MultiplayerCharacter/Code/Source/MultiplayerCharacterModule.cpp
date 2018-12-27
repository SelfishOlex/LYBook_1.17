

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include <MultiplayerCharacterSystemComponent.h>
#include <InputCaptureComponent.h>
#include <CameraControlsComponent.h>
#include <PlayerControlsComponent.h>
#include <TimedProjectileComponent.h>
#include <PebbleSpawnerComponent.h>
#include <FootstepComponent.h>

namespace MultiplayerCharacter
{
    class MultiplayerCharacterModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MultiplayerCharacterModule, "{4F62B4A7-8B93-4582-8179-E9B81DFB2467}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MultiplayerCharacterModule, AZ::SystemAllocator, 0);

        MultiplayerCharacterModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                MultiplayerCharacterSystemComponent::CreateDescriptor(),
                InputCaptureComponent::CreateDescriptor(),
                CameraControlsComponent::CreateDescriptor(),
                PlayerControlsComponent::CreateDescriptor(),
                TimedProjectileComponent::CreateDescriptor(),
                PebbleSpawnerComponent::CreateDescriptor(),
                FootstepComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MultiplayerCharacterSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(MultiplayerCharacter_ef30c7d985bd4150b75452a44b4744ca, MultiplayerCharacter::MultiplayerCharacterModule)
