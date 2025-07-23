#pragma once

namespace umediator
{
	template <typename TResponse>
	struct IRequest
	{
		using ResponseType = TResponse;
		virtual ~IRequest() = default;
	};
}