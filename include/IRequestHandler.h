#pragma once

namespace mediator
{
	template <typename TRequest, typename TResponse>
	struct IRequestHandler
	{
		virtual ~IRequestHandler() = default;
		virtual TResponse Handle(const TRequest& request) = 0;
	};
}
