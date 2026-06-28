#pragma once
#include "item.hpp"
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

class IView;

class MyDocument
{
public:
    MyDocument();
    ~MyDocument();
public:
    void newDocument();
    void clearDocument();
public:
    bool open(const std::string& filePath);
    bool save(const std::string& filePath) const;
public:
    IdItem addItem(PtrBaseItem item);
    bool removeItem(IdItem id);
public:
    const BaseItem* getPrimitiveById(IdItem id) const;
public:
    void render(IView& view) const;
private:
    std::vector<PtrBaseItem> m_Items;
};