#include "manager.hpp"
#include "view.hpp"

MyController::MyController(IView* view)
    : m_ptrDoc(std::make_unique<MyDocument>())
    , m_view(view)
{

}

void MyController::newDocument()
{
    m_ptrDoc->clearDocument();
    update();
}

bool MyController::importDocument(const std::string& path)
{
    bool bRes = m_ptrDoc->open(path);
    update();
    return bRes;
}

bool MyController::exportDocument(const std::string& path)
{
    return m_ptrDoc->save(path);
}

void MyController::addLineSeg(PointF_2D pntB, PointF_2D pntE)
{
    auto item = std::make_unique<LineSeg>(pntB, pntE);
    addItem(std::move(item));
}

void MyController::addRectangle(PointF_2D pnt, float width, float height)
{
    auto item = std::make_unique<Rectangle>(pnt, width, height);
    addItem(std::move(item));
}

void MyController::addCircle(PointF_2D pntC, float radius)
{
    auto item = std::make_unique<Circle>(pntC, radius);
    addItem(std::move(item)); 
}

void MyController::addItem(PtrBaseItem item)
{
    if (item) 
    {
        m_ptrDoc->addItem(std::move(item));
        update();
    }
}

bool MyController::deleteItem(IdItem id)
{
    bool bRes = m_ptrDoc->removeItem(id);
    if (bRes) 
        update();
    return bRes;
}

void MyController::update() const
{
    if (m_view)
        m_ptrDoc->render(*m_view);
}