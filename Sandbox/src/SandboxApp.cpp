#include <Hazel.h>
#include<stdio.h>

// Sandbox�࣬�̳���Hazel::Application
class Sandbox : public Hazel::Application
{
public:
    // ���캯��
    Sandbox()
    {
    }
    // ��������
    ~Sandbox()
    {
    }
};

// ����CreateApplication����������һ��Hazel::Application���ʵ��
Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}
