#pragma once

namespace mediator
{
	template <typename TResponse>
	struct IRequest
	{
		using ResponseType = TResponse;
		virtual ~IRequest() = default;
	};
}
