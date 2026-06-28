#pragma once
#include "item.hpp"

class IView
{
public:
    virtual ~IView() = default;
    virtual void draw(const BaseItem& item) = 0;
};

class MyView : public IView
{
public:
    void draw(const BaseItem& item) override
    {
        std::cout << "Draw my view" << std::endl;
        item.Draw();
    };
};