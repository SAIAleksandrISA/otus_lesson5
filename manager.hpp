#pragma once
#include <memory>
#include <string>
#include "document.hpp"

class IView;

class MyController 
{
public:
    MyController(IView* view);
public:
    void newDocument();
    bool importDocument(const std::string& path);
    bool exportDocument(const std::string& path);
public:
    void addLineSeg(PointF_2D pntB, PointF_2D pntE);
    void addRectangle(PointF_2D pnt, float width, float height);
    void addCircle(PointF_2D pntC, float radius);
public:
    void addItem(PtrBaseItem item);
    bool deleteItem(IdItem id);
public:
    void update() const;
private:
    std::unique_ptr<MyDocument> m_ptrDoc;
    IView* m_view;
};