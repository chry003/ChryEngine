#pragma once

#include "Event/Event.hpp"
#include "Core/Timer.hpp"

namespace Chry
{

	class Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float dt) {}
		virtual void OnEvent(Event& event) {}
	};

}
