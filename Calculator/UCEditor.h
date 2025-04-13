#pragma once
#include "Convertor.h"
#include "UException.h"
#include "UPEditor.h"

class CEditor : public TPEditor
{
private:
    bool isRealPart = true;

public:
    std::string addIm(const int& j);

    std::string addSeparator() override;

    std::string Bs() override;

    std::string clear() override;
};