#pragma once
#include "Stellar/Events/Event.h"

#include <sstream>
namespace Stellar
{
	class STELLAR_API MouseMovedEvent: public Event 
	{
	public:
		MouseMovedEvent(float i_X, float i_Y) 
			: m_MouseX(i_X), m_MouseY(i_Y) {}
		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse|EventCategoryInput)
	protected:
	private:
		float m_MouseX, m_MouseY;
	};
	class STELLAR_API MouseScrolledEvent: public Event
	{
	public:
		MouseScrolledEvent(float i_XOffset, float i_YOffset) 
			: m_XOffset(i_XOffset), m_YOffset(i_YOffset) {}
		inline float GetXOffset() { return m_XOffset; }
		inline float GetYOffset() { return m_YOffset; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};
	class STELLAR_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int i_Button) 
			: m_Button(i_Button) {}
		int m_Button;
	};

	class STELLAR_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int i_Button)
			:MouseButtonEvent(i_Button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	class STELLAR_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int i_Button)
			:MouseButtonEvent(i_Button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
