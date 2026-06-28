#include "item.hpp"

static IdItem generaitUnicID()
{
    static IdItem curId = 0;
    return ++curId;
}

//--------BaseItem----------------------------------
BaseItem::BaseItem(ItemType eType)
    : m_eType(eType)
    , m_nId(generaitUnicID())
{

}

//--------LineSeg----------------------------------
LineSeg::LineSeg(PointF_2D pntBeg, PointF_2D pntEnd)
    : BaseItem(ItemType::it_LineSeg)
    , m_pntBeg(pntBeg)
    , m_pntEnd(pntEnd)
{

}

void LineSeg::Draw(std::ostream& os) const
{
    os << "Type = LineSeg" << std::endl;
    os << m_pntBeg.x << " " << m_pntBeg.y << std::endl;
    os << m_pntEnd.x << " " << m_pntEnd.y << std::endl;
}

void LineSeg::write(std::ostream& os) const
{
    os << "write LineSeg" << std::endl;
}

void LineSeg::read(std::istream& is)
{
    std::cout << "read LineSeg" << std::endl;
    is >> m_pntBeg.x >> m_pntBeg.y >> m_pntEnd.x >> m_pntEnd.y;
}

//--------Rectangle----------------------------------
Rectangle::Rectangle(PointF_2D pnt, float fWidth, float fHeight)
    : BaseItem(ItemType::it_Rectangle)
    , m_pnt(pnt)
    , m_fWidth(fWidth)
    , m_fHeight(fHeight)
{

}

void Rectangle::Draw(std::ostream& os) const
{
    os << "Type = Rectangle" << std::endl;
    os << m_pnt.x << " " << m_pnt.y << std::endl;
    os << m_fWidth << std::endl;
    os << m_fHeight << std::endl;
}

void Rectangle::write(std::ostream& os) const
{
    os << "write Rectangle" << std::endl;
}

void Rectangle::read(std::istream& is)
{
    std::cout << "read Rectangle" << std::endl;
    is >> m_pnt.x >> m_pnt.y >> m_fWidth >> m_fHeight;
}

//--------Circle----------------------------------
Circle::Circle(PointF_2D pntC, float fRadius)
    : BaseItem(ItemType::it_Circle)
    , m_pntCenter(pntC)
    , m_fRadius(fRadius)
{

}

void Circle::Draw(std::ostream& os) const
{
    os << "Type = Circle" << std::endl;
    os << m_pntCenter.x << " " << m_pntCenter.y << std::endl;
    os << m_fRadius << std::endl;
}

void Circle::write(std::ostream& os) const
{
    os << "write Circle" << std::endl;
}

void Circle::read(std::istream& is)
{
    std::cout << "read Circle" << std::endl;
    is >> m_pntCenter.x >> m_pntCenter.y >> m_fRadius;
}