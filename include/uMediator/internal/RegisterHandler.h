#pragma once
#include "Mediator.h"
#define UMEDIATOR_REGISTER_HANDLER(RequestType, HandlerType, InjectionType) \
namespace umediator::static_dispatch \
{ \
    template <> \
    struct StaticDispatcher<RequestType> \
    { \
        static HandlerType& GetHandler(umediator::Mediator& mediator) \
        { \
            return mediator.GetInjection<InjectionType>().template create<HandlerType&>(); \
        } \
        \
        static typename RequestType::ResponseType Dispatch(const RequestType& request, umediator::Mediator& mediator) \
        { \
            return GetHandler(mediator).Handle(request); \
        } \
    }; \
}
