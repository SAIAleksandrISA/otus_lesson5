#pragma once
#include <iostream>
#include <memory>

using IdItem = int;

struct PointF_2D
{
    float x = 0.0f;
    float y = 0.0f;
};

class BaseItem
{
public:
    enum class ItemType
    {
        it_Unknown,
        it_LineSeg,
        it_Rectangle,
        it_Circle
    };
public:
    BaseItem(ItemType eType = ItemType::it_Unknown);
    virtual ~BaseItem() = default;
public:
    virtual void Draw(std::ostream& os = std::cout) const = 0;
    IdItem getId() const { return m_nId; }
    ItemType getType() const { return m_eType; }
public:
    virtual void write(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
private:
    ItemType m_eType;
    IdItem m_nId;
};

using PtrBaseItem = std::unique_ptr<BaseItem>;

class LineSeg : public BaseItem
{
public:
    LineSeg(PointF_2D pntBeg, PointF_2D pntEnd);
    ~LineSeg() = default;
public:
    void Draw(std::ostream& os = std::cout) const override;
    void write(std::ostream& os = std::cout) const override;
    void read(std::istream& is) override;
private:
    PointF_2D m_pntBeg;
    PointF_2D m_pntEnd;
};

class Rectangle : public BaseItem
{
public:
    Rectangle(PointF_2D pnt, float fWidth, float fHeight);
    ~Rectangle() = default;
public:
    void Draw(std::ostream& os = std::cout) const override;
    void write(std::ostream& os = std::cout) const override;
    void read(std::istream& is) override;
private:
    PointF_2D m_pnt;
    float m_fWidth = 0.0f;
    float m_fHeight = 0.0f;
};

class Circle : public BaseItem
{
public:
    Circle(PointF_2D pntC, float fRadius);
    ~Circle() = default;
public:
    void Draw(std::ostream& os = std::cout) const override;
    void write(std::ostream& os = std::cout) const override;
    void read(std::istream& is) override;
private:
    PointF_2D m_pntCenter;
    float m_fRadius = 0.0f;
};