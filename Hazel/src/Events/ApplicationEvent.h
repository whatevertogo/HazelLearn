#pragma once

#include <sstream>
#include "Event.h"

namespace Hazel
{
    class HAZEL_API WindowsResizeEvent : public Event
    {
    public:
        WindowsResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height)
        {
        }

        [[nodiscard]] inline unsigned int GetWidth() const { return m_Width; }
        [[nodiscard]] inline unsigned int GetHeight() const { return m_Height; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int m_Width, m_Height;
    };

    class HAZEL_API WindowsCloseEvent : public Event
    {
        
    };
}
