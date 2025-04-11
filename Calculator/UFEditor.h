#pragma once
#include "Convertor.h"
#include "UException.h"
#include "UPEditor.h"

class FEditor : public TPEditor
{
private:
    bool isNumerator = true;

public:
    std::string addDigit(int digit) override;

    std::string addSeparator() override;

    std::string Bs() override;

    std::string clear() override;
};