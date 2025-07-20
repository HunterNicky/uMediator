#pragma once
#include <any>
#include <stdexcept>

namespace mediator
{
	namespace static_dispatch
	{
		template <typename TRequest>
		struct StaticDispatcher;
	}

	class Mediator final
	{
	public:
		Mediator() = default;
		~Mediator() = default;

		template <typename TRequest>
		typename TRequest::ResponseType Send(const TRequest& request)
		{
			return static_dispatch::StaticDispatcher<TRequest>::Dispatch(request, *this);
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
