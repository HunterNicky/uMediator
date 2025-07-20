#pragma once
#include "Mediator.h"

namespace mediator::static_dispatch
{
	template <typename>
	inline constexpr bool kDependentFalse = false;

	template <typename TRequest>
	struct StaticDispatcher
	{
		static typename TRequest::ResponseType Dispatch(const TRequest& request, mediator::Mediator& mediator)
		{
			static_assert(kDependentFalse<TRequest>,
			              "No static dispatch handler found for this request type. Please specialize `StaticDispatcher<TRequest>` for your request type.")
				;
			throw std::runtime_error("No static dispatch handler found for this request type.");
		}
	};
}
