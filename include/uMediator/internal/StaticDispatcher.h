#pragma once

namespace umediator
{
	class Mediator;
}

namespace umediator::static_dispatch
{
	template <typename>
	inline constexpr bool kDependentFalse = false;

	template <typename TRequest>
	struct StaticDispatcher
	{
		static typename TRequest::ResponseType Dispatch(const TRequest& request, Mediator& mediator)
		{
			static_assert(
				kDependentFalse<TRequest>,
				">>> MEDIATOR ERROR: NO HANDLER REGISTERED FOR THIS REQUEST TYPE. <<<\n"
				"    Possible solutions:\n"
				"    1. Did you forget to #include the corresponding Handler's header file (.h) where you are calling mediator.Send()?\n"
				"       Example: #include \"handlers/MyRequestHandler.h\"\n\n"
				"    2. Did you forget to use the REGISTER_HANDLER(RequestType, HandlerType, ...) macro in the handler's header file?\n"
			);
			throw std::runtime_error("Mediator: No registered handler for the request type.");
		}
	};
}
