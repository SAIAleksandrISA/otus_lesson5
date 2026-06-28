#include "document.hpp"
#include "view.hpp"

MyDocument::MyDocument()
{

}

MyDocument::~MyDocument()
{

}

void MyDocument::newDocument()
{
    std::cout << "Init new Document " << std::endl;
}

void MyDocument::clearDocument()
{
    std::cout << "Clear document " << std::endl;
    m_Items.clear();
}

bool MyDocument::open(const std::string& filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile.is_open())
        return false;

    clearDocument();

    std::string line;
    while (std::getline(inFile, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string typeName;
        ss >> typeName;

        PtrBaseItem newItem = nullptr;
        if (typeName == "Circle")
            newItem = std::make_unique<Circle>(PointF_2D{}, 0.0f);
        else if (typeName == "Rectangle")
            newItem = std::make_unique<Rectangle>(PointF_2D{}, 0.0f, 0.0f);
        else if (typeName == "LineSeg")
            newItem = std::make_unique<LineSeg>(PointF_2D{}, PointF_2D{});
        else
            continue;

        if (newItem)
        {
            newItem->read(ss);
            m_Items.push_back(std::move(newItem));
        }
    }
    return true;
}

bool MyDocument::save(const std::string& filePath) const
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
        return false;

    outFile << m_Items.size() << std::endl;

    for (const auto& item : m_Items)
    {
        if (item)
            item->write(outFile);
    }
    return true;
}

IdItem MyDocument::addItem(PtrBaseItem item)
{
    IdItem id = item->getId();
    m_Items.push_back(std::move(item));
    return id;
}

bool MyDocument::removeItem(IdItem id)
{
    auto findItem = std::find_if(m_Items.begin(), m_Items.end(),
        [id](const PtrBaseItem& item)
        {
            return item && item->getId() == id;
        });

    if (findItem != m_Items.end())
    {
        m_Items.erase(findItem);
        return true;
    }
    return false;
}

const BaseItem* MyDocument::getPrimitiveById(IdItem id) const
{
    auto findItem = std::find_if(m_Items.begin(), m_Items.end(),
        [id](const PtrBaseItem& item)
        {
            return item && item->getId() == id;
        });

    if (findItem != m_Items.end())
        return findItem->get();

    return nullptr;
}

void MyDocument::render(IView& view) const
{
    std::cout << "Rendering MyDocument" << std::endl;
    for (const auto& item : m_Items)
    {
        if (item)
            view.draw(*item);
    }
}
