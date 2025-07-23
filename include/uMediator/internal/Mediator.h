#pragma once

#include <any>
#include <functional>
#include <future>
#include <stdexcept>
#include "StaticDispatcher.h"

namespace umediator
{
	class Mediator final
	{
	public:
		Mediator() = default;
		~Mediator() = default;

		template <typename TRequest>
		typename TRequest::ResponseType Send(const TRequest& request)
		{
			if constexpr (std::is_same_v<typename TRequest::ResponseType, void>)
			{
				static_dispatch::StaticDispatcher<TRequest>::Dispatch(request, *this);
				return;
			}
			else
			{
				return static_dispatch::StaticDispatcher<TRequest>::Dispatch(request, *this);
			}
		}

		template <typename TRequest>
		std::future<typename TRequest::ResponseType> SendAsync(const TRequest& request)
		{
			return std::async(std::launch::async, [this, request]
			{
				if constexpr (std::is_same_v<typename TRequest::ResponseType, void>)
				{
					static_dispatch::StaticDispatcher<TRequest>::Dispatch(request, *this);
				}
				else
				{
					return static_dispatch::StaticDispatcher<TRequest>::Dispatch(request, *this);
				}
			});
		}

		template <typename TInjection>
		void Inject(TInjection& injection)
		{
			injection_ = std::ref(injection);
		}

		template <typename TInjection>
		[[nodiscard]] TInjection& GetInjection() const
		{
			if (injection_.has_value())
			{
				return std::any_cast<std::reference_wrapper<TInjection>>(injection_).get();
			}
			throw std::runtime_error("Injection not found.");
		}

	private:
		std::any injection_;
	};
}
