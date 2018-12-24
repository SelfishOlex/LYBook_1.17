
#pragma once

#include <AzCore/Component/Component.h>

#include <MyGem/MyGemBus.h>

namespace MyGem
{
    class MyGemSystemComponent
        : public AZ::Component
        , protected MyGemRequestBus::Handler
    {
    public:
        AZ_COMPONENT(MyGemSystemComponent, "{D32C9796-1409-4FD6-B21C-2AB432D42F32}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // MyGemRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
