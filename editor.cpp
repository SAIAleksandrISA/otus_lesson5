#include "view.hpp"
#include "manager.hpp"

MyView g_view;
MyController g_controller(&g_view);


void OnBtnLineSeg() 
{
    g_controller.addLineSeg({0.0f, 0.0f},{10.0f, 6.0f});
}

void OnBtnRectangle() 
{
    g_controller.addRectangle({0.0f, 00.0f}, 10.0f, 6.0f);
}

void OnBtnCircle() 
{
    g_controller.addCircle({5.0f, 3.0f}, 5.0f);
}

void onBtnDeleteItem() 
{
    IdItem curSelItemId = 2;
    if (!g_controller.deleteItem(curSelItemId)) 
        std::cout << "Item not found!" << std::endl;
}

void OnBtnNewDoc() 
{
    g_controller.newDocument();
}

void OnBtnExportDoc() 
{
    std::string path = "C://TEMP//mydoc.txt";
    if (!g_controller.exportDocument(path))
        std::cout << "Ñrash export doc" << std::endl;
}

void OnBtnImportDoc()
{
    std::string path = "C://TEMP//mydoc.txt";
    if (!g_controller.importDocument(path))
        std::cout << "Ñrash import doc" << std::endl;
}

int main()
{
    OnBtnNewDoc();
    OnBtnLineSeg();
    OnBtnRectangle();
    OnBtnCircle();
    onBtnDeleteItem();
    OnBtnExportDoc();

    return 0;
}