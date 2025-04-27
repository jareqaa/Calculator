#pragma once
#include "Convertor.h"
#include "UException.h"
#include "UPEditor.h"

class FEditor : public TPEditor
{
public:
    std::string addSeparator() override;
};