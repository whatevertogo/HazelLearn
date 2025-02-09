#include <Hazel.h>
#include<stdio.h>

// Sandbox类，继承自Hazel::Application
class Sandbox : public Hazel::Application
{
public:
    // 构造函数
    Sandbox()
    {
    }
    // 析构函数
    ~Sandbox()
    {
    }
};

// 定义CreateApplication函数，返回一个Hazel::Application类的实例
Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}
