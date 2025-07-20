#pragma once

#define REGISTER_HANDLER(RequestType, HandlerType, InjectionType)                                \
    namespace mediator::static_dispatch                                                          \
    {                                                                                            \
        template <>                                                                              \
        struct StaticDispatcher<RequestType>																										 \
        {                                                                                        \
            static typename RequestType::ResponseType Dispatch(const RequestType& request, mediator::Mediator& mediator) \
            {                                                                                    \
                static auto& injection = mediator.GetInjection<InjectionType>();                 \
                HandlerType handler = injection.template create<HandlerType>();                  \
                return handler.Handle(request);                                                  \
            }                                                                                    \
        };                                                                                       \
    }
